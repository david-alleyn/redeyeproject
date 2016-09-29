#include "wx/wxprec.h"
#include "RedDotExperiment.h"


RedDotExperiment::RedDotExperiment(string name, int duration) : Experiment(name, duration)
{
}


RedDotExperiment::~RedDotExperiment()
{
}

bool RedDotExperiment::initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts)
{
	return false;
}

bool RedDotExperiment::runFrame(double currentTime)
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
