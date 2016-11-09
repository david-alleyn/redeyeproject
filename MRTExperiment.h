#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <map>

#define GLM_FORCE_SWIZZLE
#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include "FBO.h"
#include "RenderTargetGrid.h"
#include "MovingCircle.h"

using namespace std;

class MRTExperiment
{
	string name;
	int duration;
	vector<SDL_Window*> windows;
	vector<SDL_GLContext> renderContexts;
	bool initialized;
	bool running;

	bool blending = true;

	RenderTargetGrid* experimentOutput;

	unsigned int rows = 11;
	unsigned int columns = 11;

	unsigned int mrtShader = 0;
	unsigned int basicShader = 0;
	glm::mat4	 modelMatrix;

	vector<int>	drawWidth;
	vector<int>	drawHeight;
	vector<glm::mat4>		m4Projection;
	vector<glm::mat4>		m4ViewMatrix;

	/*double leftMargin = 0.00;
	double rightMargin = 0.00;
	double topMargin = 0.00;
	double bottomMargin = 0.00;
	double horizontalSep = 0.00;
	double verticalSep = 0.00;*/

	double leftMargin = 0.02;
	double rightMargin = 0.02;
	double topMargin = 0.02;
	double bottomMargin = 0.02;
	double horizontalSep = 0.01;
	double verticalSep = 0.01;

	int numberOfDots = 100;
	double sizeOfDots = 30.0;
	glm::vec4 colorOfDots = glm::vec4(1.0f, 0.0f, 0.0f, 1.0f);
	double speedOfDots = 0.1;
	vector<MovingCircle*> dots;

public:
	MRTExperiment(string name, int duration);
	virtual ~MRTExperiment();

	virtual bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts);
	virtual bool run(double currentTime);
	virtual bool cleanup();
	virtual int timeRemaining();
};

