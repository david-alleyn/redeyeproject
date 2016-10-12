#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MRTExperiment.h"


#define GLEW_STATIC
#include <GL/glew.h>

#include <cmath>

#include <SDL.h>

#include "ShaderLoader.h"


MRTExperiment::MRTExperiment(string name, int duration)
{
	this->name = name;
	this->duration = duration;
}


MRTExperiment::~MRTExperiment()
{
}

inline bool MRTExperiment::initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts)
{
	mrtQuadX = (((NDCWidth - (NDCWidth * leftMargin) - (NDCWidth * rightMargin) - ((NDCWidth * horizontalSep) * ((double) columns - 1.0)))) / columns) - 1.0;
	mrtQuadY = (((NDCHeight - (NDCHeight * topMargin) - (NDCHeight * bottomMargin) - ((NDCHeight * verticalSep) * ((double) rows - 1.0)))) / rows) - 1.0;

	vector<glm::vec2> offsets;

	for (unsigned int row = 0; row < rows; row++) {
		for (unsigned int column = 0; column < columns; column++) {
			double xOffset = (leftMargin * NDCWidth) + ((double)column * (leftMargin * NDCWidth)) + ((double)column * ((mrtQuadX + 1) * NDCWidth));
			double yOffset = (bottomMargin * NDCHeight) + ((double)row * (bottomMargin * NDCHeight)) + ((double)row * ((mrtQuadY + 1) * NDCHeight));
			offsets.push_back(glm::vec2(xOffset, yOffset));
		}
	}

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		wxLogMessage("Error: " + wxString(glewGetErrorString(err)));
	}

	windows = allWindows;
	renderContexts = allRenderContexts;

	//USING FIRST CONTEXT / WINDOW

	SDL_GL_MakeCurrent(windows[0], renderContexts[0]);


	// CREATE SHADER

	GLint success = 0;
	GLchar shaderInfoLog[256];
	GLuint vertexShaderHandle = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShaderHandle = glCreateShader(GL_FRAGMENT_SHADER);

	mrtShader = ShaderLoader::loadShader("renderToTexture.vs", "renderToTexture.fs");
	basicShader = ShaderLoader::loadShader("basicShader.vs", "basicShader.fs");

	// LOAD COLORS OR TEXTURES

	int texDimensions = 256; //must be factor of 2
	double radius = ((double)texDimensions) / 2.0f;
	glm::vec4 *texData = new glm::vec4[texDimensions * texDimensions];
	for (int i = 0; i < texDimensions * texDimensions; i += texDimensions)
	{
		for (int j = 0; j < texDimensions; ++j)
		{
			double xNorm = (i / texDimensions) + 1;
			double yNorm = (j + 1);
			//if (j % 2 == 0)
			//{
			//	texData[i + j] = glm::vec4(0, 0, 0, 1); //
			//}
			//else
			//{
			double distanceFromCenter = sqrt(pow((double)xNorm - (double)radius, 2) + pow((double)yNorm - (double)radius, 2));

			if (distanceFromCenter <= radius) {
				texData[i + j] = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
			}
			else {
				texData[i + j] = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
			}
			//}


		}
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 256, 256, 0, GL_RGBA, GL_FLOAT, texData);

	//offsets sent as a texture

	glGenTextures(1, &offsetDataTex);
	glBindTexture(GL_TEXTURE_1D, offsetDataTex);
	glTexImage1D(GL_TEXTURE_1D, 0, GL_RG, offsets.size(), 0, GL_RG, GL_FLOAT, &offsets[0]);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//// set the texture to use slot 0 in the shader
	//GLuint texUniformID = glGetUniformLocation(basicShader, "diffuseTexture");
	//glUniform1i(texUniformID, 0);

	// cleanup Texture Data:
	delete[] texData;
	texData = nullptr;

	// now create a quad:
	Vertex aoVertices[4];
	aoVertices[0].v4Position = glm::vec4(-2, 0, -2, 1);
	aoVertices[0].v2uv = glm::vec2(0, 0);
	aoVertices[0].v4colour.xyzw = 1.0f; // = glm::vec4(0,1,0,1);
	aoVertices[1].v4Position = glm::vec4(2, 0, -2, 1);
	aoVertices[1].v2uv = glm::vec2(1, 0);
	aoVertices[1].v4colour = glm::vec4(1, 0, 0, 1);
	aoVertices[2].v4Position = glm::vec4(2, 0, 2, 1);
	aoVertices[2].v2uv = glm::vec2(1, 1);
	aoVertices[2].v4colour = glm::vec4(0, 1, 0, 1);
	aoVertices[3].v4Position = glm::vec4(-2, 0, 2, 1);
	aoVertices[3].v2uv = glm::vec2(0, 1);
	aoVertices[3].v4colour = glm::vec4(0, 0, 1, 1);

	unsigned int auiIndex[6] = {
		3,1,0,
		3,2,1
	};

	// CREATE FBO / VBO / (maybe index buffer?)

	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), aoVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), auiIndex, GL_STATIC_DRAW);

	//Prepare render target geometry and other info
	struct MrtVertex {
		glm::vec3 position;
		glm::vec2 texcoord;
		MrtVertex(const glm::vec3 &pos, const glm::vec2 &tc) { position = pos; texcoord = tc; }
	};


	//Construct a quad that 
	std::vector<MrtVertex> vertices;
	vertices.push_back(MrtVertex(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	vertices.push_back(MrtVertex(glm::vec3(mrtQuadX, -1, 0), glm::vec2(1, 0)));
	vertices.push_back(MrtVertex(glm::vec3(mrtQuadX, mrtQuadY, 0), glm::vec2(1, 1)));
	vertices.push_back(MrtVertex(glm::vec3(-1, mrtQuadY, 0), glm::vec2(0, 1)));
	std::vector<unsigned int> indices;
	indices.push_back(0); indices.push_back(1); indices.push_back(2);
	indices.push_back(2); indices.push_back(3); indices.push_back(0);

	glGenBuffers(1, &fboVbo);
	glBindBuffer(GL_ARRAY_BUFFER, fboVbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MrtVertex) * 4, &vertices[0], GL_STATIC_DRAW);
	glGenBuffers(1, &fboIbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, fboIbo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &indices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
	glEnableVertexAttribArray(1); glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));

	// ---- WINDOW SPECIFIC STUFF

	for (int i = 0; i < windows.size(); i++)
	{
		SDL_GL_MakeCurrent(windows[i], renderContexts[i]);

		//Get drawable area size for each window
		int width = 0;
		int height = 0;

		SDL_GL_GetDrawableSize(windows[i], &width, &height);
		drawWidth.push_back(width);
		drawHeight.push_back(height);

		fbos[i].GenerateFBO(width, height);

		//sync to refresh rate
		SDL_GL_SetSwapInterval(1);

		// Setup VAO:
		vaos[i] = 0;
		glGenVertexArrays(1, &(vaos[i]));
		glBindVertexArray(vaos[i]);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 16);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 24);

		glUseProgram(mrtShader);

		fboVao[i] = 0;
		glGenVertexArrays(1, &fboVao[i]);
		glBindVertexArray(fboVao[i]);

		glBindBuffer(GL_ARRAY_BUFFER, fboVbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, fboIbo);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));

		// Setup Matrix:
		/*m4Projection.push_back(glm::perspective(45.0f, 1000.0f / 600.0f, 0.1f, 1000.0f));*/
		//m4Projection.push_back(glm::ortho(-(width /2),width / 2,-(height/2),height/2,-10, 10));

		float aspect = (float)width / (float)height;
		wxLogMessage(wxString(std::to_string(aspect)));

		if (aspect >= 1.0) {
			m4Projection.push_back(glm::ortho(-10.0f * aspect, 10.0f * aspect, -10.0f, 10.0f, 0.0f, 10000.0f));
		}
		else {
			m4Projection.push_back(glm::ortho(-10.0f, 10.0f, -10.0f / aspect, 10.0f / aspect, 0.0f, 10000.0f));
		}


		m4ViewMatrix.push_back(glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

		// set OpenGL Options:
		glViewport(0, 0, width, height);
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		glEnable(GL_DEPTH_TEST);
		//glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	running = true;


	return false;
}

bool MRTExperiment::run(double currentTime)
{
	//for each window/context

	// glclear
	// useshader
	// get proj,view,model uniform locations
	// set uniformmatrix pointers
	// bind texters/vertex arrays 

	//RENDER CALL
	//SWAP WINDOW BUFFERS

	while (running)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}

			if (event.type == SDL_KEYDOWN)
			{
				SDL_Keycode keyPressed = event.key.keysym.sym;

				switch (keyPressed)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				}
			}
		}

		// Keep Running!
		// get delta time for this iteration:
		float fDeltaTime = SDL_GetTicks() / 1000.0f;

		glm::mat4 identity;

		modelMatrix = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
		modelMatrix = glm::rotate(modelMatrix, fDeltaTime, glm::vec3(0.0f, 1.0f, 0.0f));

		//modelMatrix = glm::scale(modelMatrix, glm::vec3(1000.0f));

		// draw each window in sequence:
		for (int i = 0; i < windows.size(); i++)
		{
			SDL_GL_MakeCurrent(windows[i], renderContexts[i]);

			//Pass 1, draw to framebuffer
			fbos[i].bind();
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			glEnable(GL_BLEND);

			glUseProgram(basicShader);

			GLuint ProjectionID = glGetUniformLocation(basicShader, "Projection");
			GLuint ViewID = glGetUniformLocation(basicShader, "View");
			GLuint ModelID = glGetUniformLocation(basicShader, "Model");

			glUniformMatrix4fv(ProjectionID, 1, false, glm::value_ptr(m4Projection[i]));
			glUniformMatrix4fv(ViewID, 1, false, glm::value_ptr(m4ViewMatrix[i]));
			glUniformMatrix4fv(ModelID, 1, false, glm::value_ptr(modelMatrix));

			GLuint texUniformID = glGetUniformLocation(basicShader, "diffuseTexture");

			glActiveTexture(GL_TEXTURE0);
			glUniform1i(texUniformID, 0);
			glBindTexture(GL_TEXTURE_2D, texture);

			glBindVertexArray(vaos[i]);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			
			glm::mat4 movedModel = glm::translate(modelMatrix, glm::vec3(0.5f));
			glUniformMatrix4fv(ModelID, 1, false, glm::value_ptr(movedModel));
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			fbos[i].unbind();

			//Pass 2 - FOR EACH RENDER TARGET - currently there is only one for testing

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(mrtShader);

			//glViewport(0, 0, drawWidth[i], drawHeight[i]);
			glActiveTexture(GL_TEXTURE0 + 1);
			glBindTexture(GL_TEXTURE_2D, fbos[i].getRGBATexture());
			GLuint tColor = glGetUniformLocation(mrtShader, "texture_color");
			glUniform1i(tColor, 1);

			glActiveTexture(GL_TEXTURE0 + 2);
			glBindTexture(GL_TEXTURE_1D, offsetDataTex);
			GLuint offsetUni = glGetUniformLocation(mrtShader, "offsets");
			glUniform1i(offsetUni, 2);

			glBindVertexArray(fboVao[i]);
			glDisable(GL_DEPTH_TEST);
			glDisable(GL_BLEND);
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, rows*columns);

			glFinish();

			SDL_GL_SwapWindow(windows[i]);
		}
	}

	return false;
}

bool MRTExperiment::cleanup()
{
	//for each window/context
	// delete context and destroy window
	// terminate glew?
	return false;
}

int MRTExperiment::timeRemaining()
{
	return 0;
}
