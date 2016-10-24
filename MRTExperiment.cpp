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


//
const double NDCWIDTH = 2;
const double NDCHEIGHT = 2;

MRTExperiment::MRTExperiment(string name, int duration)
{
	this->name = name;
	this->duration = duration;
}


MRTExperiment::~MRTExperiment()
{
}

bool MRTExperiment::initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts)
{

	GLenum err = glewInit();

	if (GLEW_OK != err)
	{
		wxLogMessage("Error: " + wxString(glewGetErrorString(err)));
	}

	windows = allWindows;
	renderContexts = allRenderContexts;

	//Make sure that we begin initialization with the first window / render context
	SDL_GL_MakeCurrent(windows[0], renderContexts[0]);


	// CREATE SHADERS
	mrtShader = ShaderLoader::loadShader("renderToTexture.vs", "renderToTexture.fs");
	basicShader = ShaderLoader::loadShader("basicShader.vs", "basicShader.fs");

	// CREATE CIRCLE TEXTURE DATA
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

	// CREATE TEXTURE HANDLE, BIND THE HANDLE, AND BUFFER THE TEXTURE
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, 256, 256, 0, GL_RGBA, GL_FLOAT, texData);

	// SET TEXTURE FILTERING OPTIONS
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
	Vertex circleQuadVertices[4];
	circleQuadVertices[0].v4Position = glm::vec4(-2, 0, -2, 1);
	circleQuadVertices[0].v2TexCoord = glm::vec2(0, 0);
	circleQuadVertices[0].v4Colour.xyzw = glm::vec4(1,1,1,1);
	circleQuadVertices[1].v4Position = glm::vec4(2, 0, -2, 1);
	circleQuadVertices[1].v2TexCoord = glm::vec2(1, 0);
	circleQuadVertices[1].v4Colour = glm::vec4(1, 0, 0, 1);
	circleQuadVertices[2].v4Position = glm::vec4(2, 0, 2, 1);
	circleQuadVertices[2].v2TexCoord = glm::vec2(1, 1);
	circleQuadVertices[2].v4Colour = glm::vec4(0, 1, 0, 1);
	circleQuadVertices[3].v4Position = glm::vec4(-2, 0, 2, 1);
	circleQuadVertices[3].v2TexCoord = glm::vec2(0, 1);
	circleQuadVertices[3].v4Colour = glm::vec4(0, 0, 1, 1);

	unsigned int circleQuadIndices[6] = {
		3,1,0,
		3,2,1
	};

	// CREATE Vertex buffers / index buffers for circleQuad

	glGenBuffers(1, &circleQuadVBO);
	glGenBuffers(1, &circleQuadIBO);

	glBindBuffer(GL_ARRAY_BUFFER, circleQuadVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circleQuadIBO);

	glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), circleQuadVertices, GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), circleQuadIndices, GL_STATIC_DRAW);


	//All relevant screen space margins and seperations converted from percentages to Normalized Device Coordinate compatible quantities.
	double leftMarginNDC = NDCWIDTH * leftMargin;
	double rightMarginNDC = NDCWIDTH * rightMargin;
	double topMarginNDC = NDCHEIGHT * topMargin;
	double bottomMarginNDC = NDCHEIGHT * bottomMargin;
	double vertSepNDC = NDCHEIGHT * verticalSep;
	double horizSepNDC = NDCWIDTH * horizontalSep;

	double totalHorizontalSepNDC = horizSepNDC * ((double)columns - 1.0);
	double totalVerticalSepNDC = vertSepNDC * ((double)rows - 1.0);

	//determine the dimension of the render target's quad by subtracting all of the space designed for margins and seperations
	//
	mrtQuadWidth = ((NDCWIDTH - leftMarginNDC - rightMarginNDC - totalHorizontalSepNDC)) / columns;
	mrtQuadHeight = ((NDCHEIGHT - topMarginNDC - bottomMarginNDC - totalVerticalSepNDC)) / rows;

	vector<glm::vec4> offsets;

	for (unsigned int row = 0; row < rows; row++) {
		for (unsigned int column = 0; column < columns; column++) {

			double xOffset = leftMarginNDC + (mrtQuadWidth * (double)column) + (horizSepNDC * (double)column);
			double yOffset = bottomMarginNDC + (mrtQuadHeight * (double)row) + (vertSepNDC * (double)row);

			offsets.push_back(glm::vec4(xOffset, yOffset, 0.0f, 0.0f));
		}
	}

	//Send the position offsets for all the render targets to the GPU as a special "texture buffer" object.
	glGenBuffers(1, &tbo);
	glBindBuffer(GL_TEXTURE_BUFFER, tbo);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * offsets.size(), &offsets[0], GL_STATIC_DRAW);

	glGenTextures(1, &offsetDataTex);
	glBindTexture(GL_TEXTURE_BUFFER, offsetDataTex);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, tbo);

	//Construct a quad for use as a render target using the calculated mrtQuad values but offset for Normalized Device Coordinates
	double mrtQuadWidthNDC = mrtQuadWidth - 1.0;
	double mrtQuadHeightNDC = mrtQuadHeight - 1.0;

	std::vector<MrtVertex> mrtQuadVertices;
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(mrtQuadWidthNDC, -1, 0), glm::vec2(1, 0)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(mrtQuadWidthNDC, mrtQuadHeightNDC, 0), glm::vec2(1, 1)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(-1, mrtQuadHeightNDC, 0), glm::vec2(0, 1)));


	// Create the indices for how the 
	std::vector<unsigned int> mrtQuadIndices;
	mrtQuadIndices.push_back(0); mrtQuadIndices.push_back(1); mrtQuadIndices.push_back(2);
	mrtQuadIndices.push_back(2); mrtQuadIndices.push_back(3); mrtQuadIndices.push_back(0);


	// CREATE Vertex buffers / index buffers for mrtQuad
	glGenBuffers(1, &mrtQuadVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mrtQuadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MrtVertex) * 4, &mrtQuadVertices[0], GL_STATIC_DRAW);
	glGenBuffers(1, &mrtQuadIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mrtQuadIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &mrtQuadIndices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
	glEnableVertexAttribArray(1); glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));

	// ---- For each WINDOW / RENDER CONTEXT, we have to setup VAOs and Vertex Attribs for all renderable objects, Projection/View Matrices and Opengl features and blend modes

	for (int i = 0; i < windows.size(); i++)
	{

		//For each window / render context, 
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

		// Setup VAOs and Vertex Attribs for circleQuad:
		circleQuadVAOs[i] = 0;
		glGenVertexArrays(1, &(circleQuadVAOs[i]));
		glBindVertexArray(circleQuadVAOs[i]);

		glBindBuffer(GL_ARRAY_BUFFER, circleQuadVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, circleQuadIBO);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 16);
		glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 24);

		//glUseProgram(mrtShader);

		// Setup VAOs and Vertex Attribs for mrtQuad:
		mrtQuadVAOs[i] = 0;
		glGenVertexArrays(1, &mrtQuadVAOs[i]);
		glBindVertexArray(mrtQuadVAOs[i]);

		glBindBuffer(GL_ARRAY_BUFFER, mrtQuadVBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mrtQuadIBO);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));


		//Setup Aspect Ratio
		float aspect = (float)width / (float)height;
		wxLogMessage(wxString(std::to_string(aspect)));

		//Setup projection and view matrices
		if (aspect >= 1.0) {
			m4Projection.push_back(glm::ortho(-10.0f * aspect, 10.0f * aspect, -10.0f, 10.0f, 0.0f, 10000.0f));
		}
		else {
			m4Projection.push_back(glm::ortho(-10.0f, 10.0f, -10.0f / aspect, 10.0f / aspect, 0.0f, 10000.0f));
		}

		m4ViewMatrix.push_back(glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

		// set OpenGL Options:
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		glEnable(GL_DEPTH_TEST);

		//TURN OFF FOR DEBUGGING
		//glEnable(GL_CULL_FACE);
		//glEnable(GL_BLEND);

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
			glViewport(0, 0, drawWidth[i], drawHeight[i]);
			glClearColor(1.0f, 0, 0, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glEnable(GL_DEPTH_TEST);
			//glEnable(GL_BLEND);

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

			glBindVertexArray(circleQuadVAOs[i]);

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			
			glm::mat4 movedModel = glm::translate(modelMatrix, glm::vec3(0.5f));
			glUniformMatrix4fv(ModelID, 1, false, glm::value_ptr(movedModel));

			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);



			fbos[i].unbind();

			//Pass 2 - FOR EACH RENDER TARGET - currently there is only one for testing

			glViewport(0, 0, drawWidth[i], drawHeight[i]);
			glClearColor(0, 1.0f, 0, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(mrtShader);

			glActiveTexture(GL_TEXTURE0 + 1);
			glBindTexture(GL_TEXTURE_2D, fbos[i].getRGBATexture());
			GLuint tColor = glGetUniformLocation(mrtShader, "texture_color");
			glUniform1i(tColor, 1);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_BUFFER, offsetDataTex);
			glUniform1i(glGetUniformLocation(mrtShader, "offsets"), 0);

			glBindVertexArray(mrtQuadVAOs[i]);
			glDisable(GL_DEPTH_TEST);
			//glDisable(GL_BLEND);
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
