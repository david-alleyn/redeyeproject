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

	//CREATE OUR CIRCLES

	unsigned int sharedVBO = 0;
	unsigned int sharedIBO = 0;

	for (int i = 0; i < numberOfDots; i++) {
		if (i == 0) {
			dots.push_back(new MovingCircle(glm::vec2(sizeOfDots), colorOfDots, glm::vec2(0.0f), speedOfDots, basicShader));
			sharedVBO = dots[0]->getVBOHandle();
			sharedIBO = dots[0]->getIBOHandle();
		}
		else {
			dots.push_back(new MovingCircle(glm::vec2(sizeOfDots), colorOfDots, glm::vec2(0.0f), speedOfDots, basicShader, sharedVBO, sharedIBO));
		}
	}

	//Create our rendering grid

	experimentOutput = new RenderTargetGrid(mrtShader, rows, columns, leftMargin, rightMargin, topMargin, bottomMargin, horizontalSep, verticalSep);

	// ---- For each WINDOW / RENDER CONTEXT, we have to setup VAOs and Vertex Attribs for all renderable objects, Projection/View Matrices and Opengl features and blend modes
	float leftBound;
	float rightBound;
	float bottomBound;
	float topBound;

	for (int i = 0; i < windows.size(); i++)
	{

		//For each window / render context, 
		SDL_GL_MakeCurrent(windows[i], renderContexts[i]);

		//Get drawable area size for each render target
		int screenWidth = 0;
		int screenHeight = 0;

		SDL_GL_GetDrawableSize(windows[i], &screenWidth, &screenHeight);

		//sync to refresh rate
		SDL_GL_SetSwapInterval(1);

		for (int dot = 0; dot < dots.size(); dot++) {
			dots[dot]->addVao();
		}

		experimentOutput->addRenderTargetVAO(screenWidth, screenHeight);

		//Setup Aspect Ratio
		//float aspect = (float)screenWidth / (float)screenHeight;
		float aspect = experimentOutput->getAspectRatio(i);
		wxLogMessage(wxString(std::to_string(aspect)));

		//Setup projection and view matrices
		if (aspect >= 1.0) {
			leftBound = -10.0f * aspect;
			rightBound = 10.0f * aspect;
			bottomBound = -10.0f;
			topBound = 10.0f;
		}
		else {
			leftBound = -10.0f;
			rightBound = 10.0f;
			bottomBound = -10.0f / aspect;
			topBound = 10.0f / aspect;
		}


		m4Projection.push_back(glm::ortho(leftBound, rightBound, bottomBound, topBound, 0.0f, 10000.0f));
		m4ViewMatrix.push_back(glm::lookAt(glm::vec3(0, 0, 10), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)));

		// set OpenGL Options:
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glEnable(GL_DEPTH_TEST);

		//TURN OFF FOR DEBUGGING
		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);

		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	for (int dot = 0; dot < dots.size(); dot++) {
		dots[dot]->setBounds(leftBound, rightBound, topBound, bottomBound);
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
				case SDLK_b:
					blending = blending ? false : true;
					break;
				}
			}
		}

		// Keep Running!
		// get delta time for this iteration:
		float fDeltaTime = SDL_GetTicks() / 1000.0f;

		glm::mat4 identity;

		modelMatrix = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

		for (int i = 0; i < dots.size(); i++) {
			dots[i]->randomMovement();
		}

		// draw each window in sequence:
		for (int window = 0; window < windows.size(); window++)
		{
			SDL_GL_MakeCurrent(windows[window], renderContexts[window]);
			
			//Pass 1, draw to framebuffer

			//if (window == 0) { //For rendering to identical screens
			//experimentOutput->bindRenderTargetFBO(0); //For rendering to identical screens

			experimentOutput->bindRenderTargetFBO(window);

			//enable blending for framebuffer
			glEnable(GL_DEPTH_TEST);

			if (blending) {
				glEnable(GL_BLEND);
				glClearColor(0.0f, 0, 0, 1.0f);
			}
			else {
				glDisable(GL_BLEND);
				glClearColor(1.0f, 0, 0, 1.0f);
			}

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



			for (int dot = 0; dot < dots.size(); dot++) {
				dots[dot]->bindVao(window);
				dots[dot]->draw(modelMatrix, m4Projection[window], m4ViewMatrix[window]);
			}

			experimentOutput->unbindRenderTargetFBO();


			//} //For rendering to identical screens

			//Pass 2 - FOR EACH RENDER TARGET - currently there is only one for testing

			int displayWidth = 0;
			int displayHeight = 0;

			//SDL_GL_GetDrawableSize(windows[window], &displayWidth, &displayHeight);
			//glViewport(0, 0, displayWidth, displayHeight);			

			if (blending) {
				glEnable(GL_BLEND);
				glClearColor(0.0f, 0, 0, 1.0f);
			}
			else {
				glDisable(GL_BLEND);
				glClearColor(0.0f, 1.0f, 0, 1.0f);
			}

			

			experimentOutput->bindRenderTargetVAO(window);
			
			//FBOs can be shared between contexts. Not useful when rendering to disimilar screens
			//experimentOutput->bindRenderTargetVAO(0);


			/*glDisable(GL_DEPTH_TEST);
			glDisable(GL_BLEND);*/
			//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
			experimentOutput->draw();

			glFinish();

 			SDL_GL_SwapWindow(windows[window]);
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
