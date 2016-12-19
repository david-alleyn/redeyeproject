#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <map>

#define GLM_FORCE_SWIZZLE
#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include "FrameBufferWrapper.h"
#include "DisplayEngine.h"
#include "RenderTargetGrid.h"
#include "MovingCircle.h"
#include "ConfigurationData.h"

using namespace std;

class MRTExperiment
{
	//Configuration Handle
	ConfigurationData* configData;

	//Tools
	DisplayEngine* displayEngine;
	RenderTargetGrid* experimentOutput;

	//Experiment state variables

	bool initialized;
	bool running;
	bool timeRemains;

	SDL_TimerID experimentTimer;

	bool debugging = true;

	unsigned int mrtShader;
	unsigned int basicShader;

	glm::mat4	 modelMatrix;

	vector<glm::mat4>		m4Projection;
	vector<glm::mat4>		m4ViewMatrix;

	vector<MovingCircle*> dots;

public:
	MRTExperiment();
	~MRTExperiment();

	bool initialize(ConfigurationData* configData);
	bool run();

	static Uint32 experimentTimeoutCallback(Uint32 interval, void *param);
};

