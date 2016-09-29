#pragma once
#include <SDL.h>
#include <vector>
#include <string>
#include <map>

#define GLM_FORCE_SWIZZLE
#include "glm/glm.hpp"
#include "glm/ext.hpp"

using namespace std;

class Experiment
{
	string name;
	int duration;
	vector<SDL_Window*> windows;
	vector<SDL_GLContext> renderContexts;
	bool initialized;

	map<unsigned int, unsigned int>	vaos;
	unsigned int vbo = 0;
	unsigned int ibo = 0;
	unsigned int texture = 0;
	unsigned int shader = 0;
	glm::mat4	 modelMatrix;

	vector<int>	drawWidth;
	vector<int>	drawHeight;
	vector<glm::mat4>		m4Projection;
	vector<glm::mat4>		m4ViewMatrix;

	struct Vertex
	{
		glm::vec4 v4Position;
		glm::vec2 v2uv;
		glm::vec4 v4colour;
	};


public:
	Experiment(string name, int duration);
	virtual ~Experiment();

	virtual bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts);
	virtual bool runFrame(double currentTime);
	virtual bool cleanup();
	virtual int timeRemaining();
};

