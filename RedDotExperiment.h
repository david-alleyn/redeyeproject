#pragma once
#include "DirectFBExperiment.h"
class RedDotExperiment :
	public DirectFBExperiment
{
public:
	RedDotExperiment(string name, int duration);
	~RedDotExperiment();

	bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts) override;
	bool run(double currentTime) override;
	bool cleanup() override;
	int timeRemaining() override;
};

