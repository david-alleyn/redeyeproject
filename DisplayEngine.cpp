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
	windows = vector<SDL_Window*>();
	glContexts = vector<SDL_GLContext>();

	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
	{
		wxLogError("SDL failed to initialize." + wxString(SDL_GetError()));
		throw "SDL_Init failed: " + string(SDL_GetError());
	}
	else
	{
		wxLogMessage("SDL initialized.");
	}

	numDisplays = SDL_GetNumVideoDisplays();

	running = false;
	
	////Create window
	////SDL_Window* window1 = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED_DISPLAY(1), SDL_WINDOWPOS_UNDEFINED_DISPLAY(1), 1500, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
	//SDL_Window* window2 = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED_DISPLAY(0), SDL_WINDOWPOS_UNDEFINED_DISPLAY(0), 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);

	////SDL_GLContext ctx1 = SDL_GL_CreateContext(window1);
	//SDL_GLContext ctx2 = SDL_GL_CreateContext(window2);
	//
	//

	////int w1, h1;
	//int w2, h2;
	////SDL_GetWindowSize(window1, &w1, &h1);
	//SDL_GetWindowSize(window2, &w2, &h2);

	////SDL_GL_MakeCurrent(window1, ctx1);
	////SDL_GL_SwapWindow(window1);
	//SDL_GL_MakeCurrent(window2, ctx2);
	//SDL_GL_SwapWindow(window2);

	wxLogMessage("DisplayEngine Instantiated.");


}

DisplayEngine::~DisplayEngine()
{
	//Properly finish all OpenGL related operations
	// STUFF

	SDL_Quit();
}

DisplayEngine *DisplayEngine::s_instance = 0;

DisplayEngine* DisplayEngine::getInstance()
{
	if (!s_instance)
		s_instance = new DisplayEngine;
	return s_instance;
}

vector<Display> DisplayEngine::enumerateAllDisplays()
{
	wxLogMessage("Enumerating all displays on the system");

	vector<Display> allDisplays;

	for(int i = 0; i < numDisplays; i++)
	{
		int numModes = SDL_GetNumDisplayModes(i);
		wxLogMessage("Display " + wxString::Format(wxT("%i"), i) + " total modes: " + wxString::Format(wxT("%i"), numModes));

		for(int j = 0; j < numModes; j++)
		{
			SDL_DisplayMode* displayMode = new SDL_DisplayMode();
			SDL_GetDisplayMode(i, j, displayMode);

			if(j == 0)
			{
				allDisplays.push_back(Display(j, displayMode->w, displayMode->h, displayMode->refresh_rate));
			}
			
			wxLogMessage("Display " + wxString::Format(wxT("%i"), i) + ", mode " + wxString::Format(wxT("%i"), j) + ": " + wxString::Format(wxT("%i"), displayMode->w) + "x" + wxString::Format(wxT("%i"), displayMode->h) + " " + wxString::Format(wxT("%i"), displayMode->refresh_rate) + "hz");
		}

	}
	return allDisplays;
}

int DisplayEngine::getFirstDisplay()
{
	return firstDisplay;
}
void DisplayEngine::setFirstDisplay(int displayIndex)
{
	if(displayIndex >= -1 && displayIndex < numDisplays)
	{
		firstDisplay = displayIndex;
	}
}

int DisplayEngine::getLastDisplay()
{
	return lastDisplay;
}
void DisplayEngine::setLastDisplay(int displayIndex)
{
	if (displayIndex >= -1 && displayIndex < numDisplays)
	{
		lastDisplay = displayIndex;
	}
}

void DisplayEngine::StartEngine()
{

	// TEMPORARY, USE DETECTED SCREENS, DONT USE PREFERENCES

	vector<Display> displays = enumerateAllDisplays();

	if(displays.size() < 1)
	{
		wxLogError("There is only 1 display, program is programmed to use only second display right now");
		throw "There is only 1 display, program is programmed to use only second display right now";
	}

	for(int i = 0; i < displays.size(); i++)
	{
		// use double buffering
		SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
		SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

		SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
		//SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
		SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 2);

		//Create window
		SDL_Window* window1 = SDL_CreateWindow("Red Eye Project", SDL_WINDOWPOS_UNDEFINED_DISPLAY(i), SDL_WINDOWPOS_UNDEFINED_DISPLAY(i), /*displays[i].maxWidth*/ 1000, /*displays[i].maxHeight*/ 600, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
		windows.push_back(window1);

		if(glContexts.size() > 0)
		{
			SDL_GL_SetAttribute(SDL_GL_SHARE_WITH_CURRENT_CONTEXT, 1);
		}

		SDL_GLContext ctx1 = SDL_GL_CreateContext(window1);
		glContexts.push_back(ctx1);
	}

	MRTExperiment* newExperiment =  new MRTExperiment("Test experiment", 0);
	//DirectFBExperiment* newExperiment = new DirectFBExperiment("Test experiment", 0);

	newExperiment->initialize(SDL_GetTicks(), windows, glContexts);

	running = true;
	
	newExperiment->run(SDL_GetTicks());

	newExperiment->cleanup();

	delete newExperiment;

	for (int i = 0; i < windows.size(); i++)
	{
		SDL_GL_DeleteContext(glContexts[i]);
		SDL_DestroyWindow(windows[i]);
	}




	/* BEGIN IDEAS

	Experiment Initialize
	 experimentObject.initialize(//MAYBE PASS IN ALL THE CONTEXTS?)

	Set "running" to true
	
	Experiment Run loop
	 Checks "running" is true
		for each monitor
			experimentObject.runFrame(pass desired context for that display)
			swap the window buffer

	Experiment cleanup
	 experimentObject.cleanup()

	 END IDEAS */
}

void DisplayEngine::StopEngine()
{
	/* BEGIN IDEAS
	 * 
	 * Set running to false
	 * 
	 * 
	 * END IDEAS
	 */
	
}
