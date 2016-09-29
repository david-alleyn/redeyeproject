#pragma once
#include "Experiment.h"
class RedDotExperiment :
	public Experiment
{
public:
	RedDotExperiment(string name, int duration);
	~RedDotExperiment();

	bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts) override;
	bool runFrame(double currentTime) override;
	bool cleanup() override;
	int timeRemaining() override;
};

