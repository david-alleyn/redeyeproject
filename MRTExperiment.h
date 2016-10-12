#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <map>

#define GLM_FORCE_SWIZZLE
#include "glm/glm.hpp"
#include "glm/ext.hpp"

#include "FBO.h"

using namespace std;

class MRTExperiment
{
	string name;
	int duration;
	vector<SDL_Window*> windows;
	vector<SDL_GLContext> renderContexts;
	bool initialized;
	bool running;

	map<unsigned int, FBO> fbos;
	map<unsigned int, unsigned int> fboVao;
	unsigned int fboVbo;
	unsigned int fboIbo;

	map<unsigned int, unsigned int>	vaos;
	unsigned int vbo = 0;
	unsigned int ibo = 0;
	unsigned int texture = 0;
	unsigned int mrtShader = 0;
	unsigned int basicShader = 0;
	glm::mat4	 modelMatrix;

	vector<int>	drawWidth;
	vector<int>	drawHeight;
	vector<glm::mat4>		m4Projection;
	vector<glm::mat4>		m4ViewMatrix;

	unsigned int offsetDataTex;

	double leftMargin = 0.05;
	double rightMargin = 0.05;
	double topMargin = 0.05;
	double bottomMargin = 0.05;
	double horizontalSep = 0.02;
	double verticalSep = 0.02;
	double NDCWidth = 2;
	double NDCHeight = 2;

	unsigned int rows = 3;
	unsigned int columns = 3;

	double mrtQuadX = 0; //renderTarget X value, between 0 and 2 for calculation. Normalized to -1 and 1;
	double mrtQuadY = 0; //renderTarget Y value, between 0 and 2 for calculation. Normalized to -1 and 1;



	struct Vertex
	{
		glm::vec4 v4Position;
		glm::vec2 v2uv;
		glm::vec4 v4colour;
	};


public:
	MRTExperiment(string name, int duration);
	virtual ~MRTExperiment();

	virtual bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts);
	virtual bool run(double currentTime);
	virtual bool cleanup();
	virtual int timeRemaining();
};

