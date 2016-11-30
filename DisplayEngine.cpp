#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "DisplayEngine.h"
#include "SDL.h"
#include <GL/glew.h>
//#include "DirectFBExperiment.h"
#include "MRTExperiment.h"

//#pragma comment (lib, "glew32s.lib")

DisplayEngine::DisplayEngine()
{
	windows = vector<Window>();

	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
	{
		wxLogError("SDL failed to initialize." + wxString(SDL_GetError()));
		throw "SDL_Init failed: " + string(SDL_GetError());
	}
	else
	{
		wxLogMessage("SDL initialized by DisplayEngine.");
	}

	if (getNumAttachedDisplays() > 1) {
		firstDisplay = 1;
		lastDisplay = getNumAttachedDisplays() - 1;
	}
	else {
		firstDisplay = 0;
		lastDisplay = 0;
	}

	running = false;

	wxLogMessage("DisplayEngine Initiated.");


}

DisplayEngine::~DisplayEngine()
{
	//Properly finish all OpenGL and SDL related operations
	
	//Destroy all windows / opengl contexts
	if (isRunning()) {
		stopEngine();
	}

	SDL_Quit();
}

DisplayEngine *DisplayEngine::s_instance = 0;

DisplayEngine* DisplayEngine::getInstance()
{
	if (!s_instance)
		s_instance = new DisplayEngine;
	return s_instance;
}

void DisplayEngine::resetInstance() {
	if (s_instance != NULL) {
		delete s_instance;
		s_instance = NULL;
	}
}

bool DisplayEngine::setUsingConfigData(ConfigurationData * configData) {

	if (isRunning()) {
		wxLogMessage("Error: In setUsingConfigData(ConfigurationData*), DisplayEngine is running!");
		return false;
	}

	if (configData->displayConfigInitialized) {

		if (configData->disp_firstMonitorIndex < getNumAttachedDisplays() && configData->disp_lastMonitorIndex < getNumAttachedDisplays()) {

			if (configData->disp_firstMonitorIndex <= configData->disp_lastMonitorIndex) {

				if (setFirstDisplay(configData->disp_firstMonitorIndex)
					&& setLastDisplay(configData->disp_lastMonitorIndex)) {
					return true;
				}
			}
		}
		return true;
	}
	else {
		return false;
	}
}

inline int DisplayEngine::getNumAttachedDisplays()
{
	return SDL_GetNumVideoDisplays();
}
inline int DisplayEngine::getFirstDisplay() {
	return firstDisplay;
}
bool DisplayEngine::setFirstDisplay(int displayIndex)
{
	if (isRunning()) {
		wxLogMessage("Error: In setFirstDisplay(int), DisplayEngine is running!");
		return false;
	}
	
	if(displayIndex >= 0 && displayIndex < getNumAttachedDisplays() && displayIndex <= getLastDisplay())
	{
		firstDisplay = displayIndex;
		return true;
	} else {
		return false;
	}
}

inline int DisplayEngine::getLastDisplay()
{
	return lastDisplay;
}
bool DisplayEngine::setLastDisplay(int displayIndex)
{
	if (isRunning()) {
		wxLogMessage("Error: In setLastDisplay(int), DisplayEngine is running!");
		return false;
	}
	
	if (displayIndex >= 0 && displayIndex < getNumAttachedDisplays() && displayIndex >= getFirstDisplay())
	{
		lastDisplay = displayIndex;
		return true;
	} else {
		return false;
	}
}

bool DisplayEngine::startEngine()
{

	if (isRunning()) {
		wxLogMessage("Error: In startEngine(), DisplayEngine is running already!");
		return false;
	}


	for (int i = getFirstDisplay(); i < getLastDisplay(); i++)
	{
		// use double buffering
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

		SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);

		SDL_DisplayMode* desktopDisplayMode = 0;

		SDL_GetDesktopDisplayMode(i, desktopDisplayMode);

		//Create window
		SDL_Window* sdl_window = SDL_CreateWindow("Red Eye Project", SDL_WINDOWPOS_UNDEFINED_DISPLAY(i), SDL_WINDOWPOS_UNDEFINED_DISPLAY(i), desktopDisplayMode->w, desktopDisplayMode->h, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
		
		/*if (glContexts.size() > 0)
		{
		SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
		}*/

		SDL_GLContext sdl_glContext = SDL_GL_CreateContext(sdl_window);

		Window window = Window(sdl_window, sdl_glContext);

		//sync to refresh rate
		SDL_GL_SetSwapInterval(1);

		windows.push_back(window);
	}

	//MRTExperiment* newExperiment =  new MRTExperiment("Test experiment", 0);
	////DirectFBExperiment* newExperiment = new DirectFBExperiment("Test experiment", 0);

	//newExperiment->initialize(SDL_GetTicks(), windows, glContexts);

	//running = true;
	//
	//newExperiment->run(SDL_GetTicks());

	//newExperiment->cleanup();

	//delete newExperiment;

	return true;
}

inline bool DisplayEngine::isRunning() {
	return running;
}

bool DisplayEngine::stopEngine()
{

	if (!isRunning()) {
		wxLogMessage("Error: In stopEngine(), DisplayEngine is not running!");
		return false;
	}


	running = false;

	for (int i = 0; i < windows.size(); i++)
	{
		SDL_GL_DeleteContext(windows[i].glContext);
		SDL_DestroyWindow(windows[i].window);
	}

	windows.clear();	

	return true;
}

inline int DisplayEngine::getCurrentActiveWindow() {
	if (!isRunning()) {
		wxLogMessage("Error: In getCurrentActiveWindow(), DisplayEngine is not running!");
		return false;
	}

	return currentlyActiveWindow;
}

inline int DisplayEngine::getNumWindows() {
	if (!isRunning()) {
		wxLogMessage("Error: In getNumWindows(), DisplayEngine is not running!");
		return false;
	}
	return windows.size();
}

bool DisplayEngine::setActiveWindow(int displayIndex) {

	if (!isRunning()) {
		wxLogMessage("Error: In setActiveDisplay(int), DisplayEngine is not running!");
		return false;
	}

	if (displayIndex >= 0 && displayIndex <= getNumWindows() - 1) {
		if (SDL_GL_MakeCurrent(windows[displayIndex].window, windows[displayIndex].glContext) == 0) {
			return true;
		}
		else {
			wxLogMessage("Error: In setActiveDisplay(int), SDL_GL_MakeCurrent error: " + wxString(SDL_GetError()));
			return false;
		}
	}
	else {
		wxLogMessage("Error: In setActiveDisplay(int), displayIndex out of Bounds");
		return false;
	}
}

bool DisplayEngine::swapActiveWindowBuffer() {

	if (!isRunning()) {
		wxLogMessage("Error: In swapActiveDisplayBuffer(), DisplayEngine is not running!");
		return false;
	}

	glFinish();
	SDL_GL_SwapWindow(windows[currentlyActiveWindow].window);
	return true;
}

bool DisplayEngine::paintWindowsBlack() {
	if (!isRunning()) {
		wxLogMessage("Error: In clearAllDisplays(), DisplayEngine is not running!");
		return false;
	}

	for (int i = 0; i < windows.size(); i++) {

		setActiveWindow(i);

		glBindFramebuffer(GL_FRAMEBUFFER, 0); //bind the default draw buffer.
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //set "display clearing color" to black
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the window
	}

	return true;
}

//Returns the drawable area size of the currently active window
//REQUIRES isRunning() to return true

bool DisplayEngine::getActiveWindowSize(int & width, int & height) {
	if (!isRunning()) {
		wxLogMessage("Error: In clearAllDisplays(), DisplayEngine is not running!");
		return false;
	}

	SDL_GL_GetDrawableSize(windows[currentlyActiveWindow].window, &width, &height);
	return true;
}

DisplayEngine::Window::Window(SDL_Window * window, SDL_GLContext glContext) {
	this->window = window;
	this->glContext = glContext;
}
