#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "RedDotExperiment.h"


RedDotExperiment::RedDotExperiment(string name, int duration) : DirectFBExperiment(name, duration)
{
}


RedDotExperiment::~RedDotExperiment()
{
}

bool RedDotExperiment::initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts)
{
	return false;
}

bool RedDotExperiment::run(double currentTime)
{
	return false;
}

bool RedDotExperiment::cleanup()
{
	return false;
}

int RedDotExperiment::timeRemaining()
{
	return 0;
}
