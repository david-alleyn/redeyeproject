#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Experiment.h"

#define GLEW_STATIC
#include <GL/glew.h>



Experiment::Experiment(string name, int duration)
{
	this->name = name;
	this->duration = duration;
}


Experiment::~Experiment()
{
}

bool Experiment::initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts)
{
	GLenum err = glewInit();
	if(GLEW_OK != err)
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

	const char *vertexShaderString = 
		"#version 130\n"
		"in vec4 Position;\n"
		"in vec2 UV;\n"
		"in vec4 Colour;\n"
		"out vec2 vUV;\n"
		"out vec4 vColour;\n"
		"uniform mat4 Projection;\n"
		"uniform mat4 View;\n"
		"uniform mat4 Model;\n"
		"void main()\n"
		"{\n"
		"vUV = UV;\n"
		"vColour = Colour;"
		"gl_Position = Projection * View * Model * Position;\n"
		"}\n"
		"\n";

	const char *fragmentShaderString = 
		"#version 130\n"
		"in vec2 vUV;\n"
		"in vec4 vColour;\n"
		"out vec4 outColour;\n"
		"uniform sampler2D diffuseTexture;\n"
		"void main()\n"
		"{\n"
		"outColour = texture2D(diffuseTexture, vUV) + vColour;\n"
		"}\n"
		"\n";

	glShaderSource(vertexShaderHandle, 1, (const char**)&vertexShaderString, 0);
	glCompileShader(vertexShaderHandle);
	glGetShaderiv(vertexShaderHandle, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(vertexShaderHandle, sizeof(shaderInfoLog), 0, shaderInfoLog);
	if (success == GL_FALSE)
	{
		wxLogError("Experiment, initialize(): Vertex Shader did not compile");
		wxLogError(shaderInfoLog);
	}

	glShaderSource(fragmentShaderHandle, 1, (const char**)&fragmentShaderString, 0);
	glCompileShader(fragmentShaderHandle);
	glGetShaderiv(fragmentShaderHandle, GL_COMPILE_STATUS, &success);
	glGetShaderInfoLog(fragmentShaderHandle, sizeof(shaderInfoLog), 0, shaderInfoLog);
	if (success == GL_FALSE)
	{
		wxLogError("Experiment, initialize(): Fragment Shader did not compile");
		wxLogError(shaderInfoLog);
		wxLogError("\n");
	}

	shader = glCreateProgram();
	glAttachShader(shader, vertexShaderHandle);
	glAttachShader(shader, fragmentShaderHandle);
	glDeleteShader(vertexShaderHandle);
	glDeleteShader(fragmentShaderHandle);

	// Vertex Attributes:
	glBindAttribLocation(shader, 0, "Position");
	glBindAttribLocation(shader, 1, "UV");
	glBindAttribLocation(shader, 2, "Colour");
	glBindFragDataLocation(shader, 0, "outColour");

	glLinkProgram(shader);
	glGetProgramiv(shader, GL_LINK_STATUS, &success);
	glGetProgramInfoLog(shader, sizeof(shaderInfoLog), 0, shaderInfoLog);
	if (success == GL_FALSE)
	{
		printf("Error: failed to link Shader Program!\n");
		printf(shaderInfoLog);
		printf("\n");
	}

	glUseProgram(shader);

	// LOAD COLORS OR TEXTURES

	glm::vec4 *texData = new glm::vec4[256 * 256];
	for (int i = 0; i < 256 * 256; i += 256)
	{
		for (int j = 0; j < 256; ++j)
		{
			if (j % 2 == 0)
			{
				texData[i + j] = glm::vec4(0, 0, 0, 1);
			}
			else
			{
				texData[i + j] = glm::vec4(1, 1, 1, 1);
			}
		}
	}

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, 256, 256, 0, GL_RGBA, GL_FLOAT, texData);

	// if textures, BIND TEXTURES

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// set the texture to use slot 0 in the shader
	GLuint texUniformID = glGetUniformLocation(shader, "diffuseTexture");
	glUniform1i(texUniformID, 0);

	

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

		SDL_GL_SetSwapInterval(1);
		// use double buffering

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

		

		// Setup Matrix:
		/*m4Projection.push_back(glm::perspective(45.0f, 1000.0f / 600.0f, 0.1f, 1000.0f));*/
		m4Projection.push_back(glm::ortho(-(width /2),width / 2,-(height/2),height/2,-10, 10));
		m4ViewMatrix.push_back(glm::lookAt(glm::vec3(4, 8, 8), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

		// set OpenGL Options:
		glViewport(0, 0, width, height);
		glClearColor(0.25f, 0.25f, 0.25f, 1);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
	}


	return false;
}

bool Experiment::runFrame(double currentTime)
{
	//for each window/context

	// glclear
	// useshader
	// get proj,view,model uniform locations
	// set uniformmatrix pointers
	// bind texters/vertex arrays 

	//RENDER CALL
	//SWAP WINDOW BUFFERS

	while (true)
	{
		// Keep Running!
		// get delta time for this iteration:
		float fDeltaTime = SDL_GetTicks() / 10000.0f;

		glm::mat4 identity;
		modelMatrix = glm::rotate(identity, fDeltaTime * 10.0f, glm::vec3(0.0f, 1.0f, 0.0f));

		// draw each window in sequence:
		for (int i = 0; i < windows.size(); i++)
		{
			SDL_GL_MakeCurrent(windows[i],renderContexts[i]);

			// clear the backbuffer to our clear colour and clear the depth buffer
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			glUseProgram(shader);

			GLuint ProjectionID = glGetUniformLocation(shader, "Projection");
			GLuint ViewID = glGetUniformLocation(shader, "View");
			GLuint ModelID = glGetUniformLocation(shader, "Model");

			glUniformMatrix4fv(ProjectionID, 1, false, glm::value_ptr(m4Projection[i]));
			glUniformMatrix4fv(ViewID, 1, false, glm::value_ptr(m4ViewMatrix[i]));
			glUniformMatrix4fv(ModelID, 1, false, glm::value_ptr(modelMatrix));

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, texture);
			glBindVertexArray(vaos[i]);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

			glFinish();

			SDL_GL_SwapWindow(windows[i]);

			//CheckForGLErrors("Render Error");
		}

		//SDL_Delay(1000 / fDeltaTime);

		//glfwPollEvents(); // process events!
	}

	return false;
}

bool Experiment::cleanup()
{
	//for each window/context
	// delete context and destroy window
	// terminate glew?
	return false;
}

int Experiment::timeRemaining()
{
	return 0;
}
