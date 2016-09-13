﻿#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "DisplayEngine.h"
#include "SDL.h"

DisplayEngine::DisplayEngine()
{


	if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) < 0)
	{
		wxLogError("SDL failed to initialize");
	}
	else
	{
		wxLogMessage("SDL initialized.");
	}

	//Use OpenGL 2.1
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GetNumDisplayModes(0);
	SDL_GetNumVideoDisplays();

	//Create window
	SDL_Window* window1 = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED_DISPLAY(1), SDL_WINDOWPOS_UNDEFINED_DISPLAY(1), 1500, 800, SDL_WINDOW_OPENGL | SDL_WINDOW_BORDERLESS);
	SDL_Window* window2 = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED_DISPLAY(0), SDL_WINDOWPOS_UNDEFINED_DISPLAY(0), 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_GLContext ctx1 = SDL_GL_CreateContext(window1);
	SDL_GLContext ctx2 = SDL_GL_CreateContext(window2);

	int w1, h1;
	int w2, h2;
	SDL_GetWindowSize(window1, &w1, &h1);
	SDL_GetWindowSize(window2, &w2, &h2);

	SDL_GL_MakeCurrent(window1, ctx1);
	SDL_GL_SwapWindow(window1);
	SDL_GL_MakeCurrent(window2, ctx2);
	SDL_GL_SwapWindow(window2);

	wxLogMessage("DisplayEngine Instantiated.");


}

DisplayEngine::~DisplayEngine()
{
	SDL_Quit();
}

DisplayEngine *DisplayEngine::s_instance = 0;

DisplayEngine* DisplayEngine::getInstance()
{
	if (!s_instance)
		s_instance = new DisplayEngine;
	return s_instance;
}