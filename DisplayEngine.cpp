#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "DisplayEngine.h"
#include "SDL.h"
#include <GL/glew.h>

//#pragma comment (lib, "glew32s.lib")

DisplayEngine::DisplayEngine()
{


	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
	{
		wxLogError("SDL failed to initialize." + wxString(SDL_GetError()));
		throw "SDL_Init failed: " + string(SDL_GetError());
	}
	else
	{
		wxLogMessage("SDL initialized.");
	}

	////Use OpenGL 3.0. The primary reason for this choice was instanced rendering.
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	numDisplays = SDL_GetNumVideoDisplays();
	

	//for(int i = 0; i < numDisplays; i++)
	//{
	//	int numModes = SDL_GetNumDisplayModes(i);
	//	wxLogMessage("Display " + wxString::Format(wxT("%i"), i) + " total modes: " + wxString::Format(wxT("%i"), numModes));

	//	for(int j = 0; j < numModes; j++)
	//	{
	//		SDL_DisplayMode* displayMode = new SDL_DisplayMode();
	//		SDL_GetDisplayMode(i, j, displayMode);
	//		wxLogMessage("Display " + wxString::Format(wxT("%i"), i) + ", mode " + wxString::Format(wxT("%i"), j) + ": " + wxString::Format(wxT("%i"), displayMode->w) + "x" + wxString::Format(wxT("%i"), displayMode->h) + " " + wxString::Format(wxT("%i"), displayMode->refresh_rate) + "hz");
	//	}

	//}




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