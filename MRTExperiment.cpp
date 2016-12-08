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

MRTExperiment::MRTExperiment()
{

}


MRTExperiment::~MRTExperiment()
{
	if (initialized) {
		//cleanup dynamic memory
		for (int i = 0; i < dots.size(); i++) {
			if (dots[i] != NULL) {
				delete dots[i];
				dots[i] = NULL;
			}
		}

		MovingCircle::resetStaticState();

		if (experimentOutput != NULL) {
			delete experimentOutput;
			experimentOutput = NULL;
		}

		/*mrtShader
			basicShader
			sharedVBO
			sharedIBO*/

		glDeleteShader(mrtShader);
		glDeleteShader(basicShader);
	}
}

bool MRTExperiment::initialize(ConfigurationData* configData)
{
	//Check that configuration data object pointer is valid
	if (configData == nullptr) {
		wxLogMessage("Error in MRTExperiment::initialize(), ConfigurationData is missing!");
		return false;
	}

	//Check to make sure that configData object is initialized
	if (configData->isFullyInitialized()) {

		displayEngine = DisplayEngine::getInstance();
		this->configData = configData;

		if (!displayEngine->isRunning()) {
			//DisplayEngine is not running
			wxLogMessage("Error in MRTExperiment::initialize(), DisplayEngine is not running, run DisplayEngine::startEngine() before initializing the experiment");
			return false;
		}

		// END OF INITIALIZATION FROM DISPLAYENGINE

		GLenum err = glewInit();

		if (GLEW_OK != err)
		{
			wxLogMessage("Error: " + wxString(glewGetErrorString(err)));
			return false;
		}

		//Make sure that we begin initialization with the first window / render context
		displayEngine->setActiveWindow(0);

		// CREATE SHADERS
		mrtShader = ShaderLoader::loadShader("renderToTexture.vs", "renderToTexture.fs");
		basicShader = ShaderLoader::loadShader("basicShader.vs", "basicShader.fs");

		//CREATE OUR CIRCLES
		unsigned int sharedVBO = 0;
		unsigned int sharedIBO = 0;

		//unsigned char (255) / 255.0f, should result in values from 0.0f to 1.0f
		glm::vec4 colorOfDots = glm::vec4(
			(float)configData->exp_selectedColour_red / 255.0f,
			(float)configData->exp_selectedColour_green / 255.0f,
			(float)configData->exp_selectedColour_blue / 255.0f,
			1.0f);

		for (int i = 0; i < configData->exp_numberOfObjects; i++) {
			if (i == 0) {
				dots.push_back(new MovingCircle(glm::vec2(configData->exp_sizeOfObjects), colorOfDots, glm::vec2(0.0f), configData->exp_objectSpeed, basicShader));
				sharedVBO = dots[0]->getVBOHandle();
				sharedIBO = dots[0]->getIBOHandle();
			}
			else {
				dots.push_back(new MovingCircle(glm::vec2(configData->exp_sizeOfObjects), colorOfDots, glm::vec2(0.0f), configData->exp_objectSpeed, basicShader, sharedVBO, sharedIBO));
			}
		}

		//Create our rendering grid

		experimentOutput = new RenderTargetGrid(
			mrtShader,
			configData->exp_rows,
			configData->exp_columns,
			configData->exp_gridLeftMargin,
			configData->exp_gridRightMargin,
			configData->exp_gridTopMargin,
			configData->exp_gridBottomMargin,
			configData->exp_gridHorizontalSeperation,
			configData->exp_gridVerticalSeperation);

		// ---- For each WINDOW / RENDER CONTEXT, we have to setup VAOs and Vertex Attribs for all renderable objects, Projection/View Matrices and Opengl features and blend modes
		float leftBound;
		float rightBound;
		float bottomBound;
		float topBound;

		for (int i = 0; i < displayEngine->getNumWindows(); i++)
		{

			//For each window / render context, 
			displayEngine->setActiveWindow(i);

			//Get drawable area size for each render target
			int screenWidth = 0;
			int screenHeight = 0;

			displayEngine->getActiveWindowSize(screenWidth, screenHeight);

			for (int dot = 0; dot < dots.size(); dot++) {
				dots[dot]->addVao();
			}

			experimentOutput->addRenderTargetVAO(screenWidth, screenHeight);

			//Setup Aspect Ratio
			//float aspect = (float)screenWidth / (float)screenHeight;
			float aspect = experimentOutput->getAspectRatio(i);
			/*wxLogMessage(wxString(std::to_string(aspect)));*/

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

		initialized = true;
		running = true;

		return true;
	}
	else {
		wxLogMessage("Error in MRTExperiment::initialize(), Configuration was only partially specified!");
		return false;
	}
}

bool MRTExperiment::run()
{
	//for each window/context

	// glclear
	// useshader
	// get proj,view,model uniform locations
	// set uniformmatrix pointers
	// bind texters/vertex arrays 

	//RENDER CALL
	//SWAP WINDOW BUFFERS

	if (!initialized) {
		wxLogMessage("Error in MRTExperiment::run(double), MRTExperiment hasn't been initialized");
		return false;
	}

	experimentTimer = SDL_AddTimer(configData->exp_timeInSeconds * 1000, &MRTExperiment::experimentTimeoutCallback, 0);
	timeRemains = true;

	if (experimentTimer <= 0) {
		wxLogMessage("Error in MRTExperiment::run(double), SDL_AddTimer error: " + wxString(SDL_GetError()));
		return false;
	}

	while (running)
	{
		SDL_Event event;
		int eventOccured = 0;

		if (timeRemains) { // Fast event checking when experiment in progress
			eventOccured = SDL_PollEvent(&event); //wait for 200ms for an event
		}
		else { // Slow, power conserving event checking when experiment has timed out.
			eventOccured = SDL_WaitEventTimeout(&event, 200);
		}

		if (eventOccured)
		{
			switch (event.type) {
			case SDL_USEREVENT: //The only user defined event happens to be fired by the experimentTimeoutCallback function
				timeRemains = false;
				if (experimentTimer != 0) SDL_RemoveTimer(experimentTimer);
				break;
			case SDL_QUIT:
				running = false;
				break;
			case SDL_KEYDOWN:
				SDL_Keycode keyPressed = event.key.keysym.sym;

				switch (keyPressed)
				{
				case SDLK_ESCAPE:
					running = false;
					break;
				case SDLK_b:
					debugging = debugging ? false : true;
					break;
				}
				break;
			}
		}

		if (timeRemains) {

			// Keep Running!
			// get delta time for this iteration:
			float fDeltaTime = SDL_GetTicks() / 1000.0f;

			glm::mat4 identity;

			modelMatrix = glm::rotate(identity, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));

			for (int i = 0; i < dots.size(); i++) {
				dots[i]->randomMovement();
			}

			// draw each window in sequence:
			for (int window = 0; window < displayEngine->getNumWindows(); window++)
			{
				displayEngine->setActiveWindow(window);

				//Pass 1, draw to framebuffer

				//if (window == 0) { //For rendering to identical screens
				//experimentOutput->bindRenderTargetFBO(0); //For rendering to identical screens

				experimentOutput->bindRenderTargetFBO(window);

				//enable blending for framebuffer
				glEnable(GL_DEPTH_TEST);

				if (debugging) {
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

				if (debugging) {
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

				displayEngine->swapActiveWindowBuffer();
			}
		}
		else { //Out of time, we don't want to break the loop, we just want to display nothing until the experimenter clears the experiment chamber

			if (!displayEngine->paintWindowsBlack()) {
				wxLogMessage("Error in MRTExperiment::run(), paintWindowsBlack() failed.");
			}
		}
	}

	return false;
}

Uint32 MRTExperiment::experimentTimeoutCallback(Uint32 timeInMilliseconds, void* param) {
	SDL_Event event;
	event.type = SDL_USEREVENT;

	SDL_PushEvent(&event);
	return(timeInMilliseconds);
}
