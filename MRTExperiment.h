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
	map<unsigned int, unsigned int> mrtQuadVAOs;
	unsigned int mrtQuadVBO;
	unsigned int mrtQuadIBO;

	map<unsigned int, unsigned int>	circleQuadVAOs;
	unsigned int circleQuadVBO = 0;
	unsigned int circleQuadIBO = 0;
	unsigned int tbo = 0;
	unsigned int offsetDataTex = 0;
	unsigned int texture = 0;
	unsigned int mrtShader = 0;
	unsigned int basicShader = 0;
	glm::mat4	 modelMatrix;

	vector<int>	drawWidth;
	vector<int>	drawHeight;
	vector<glm::mat4>		m4Projection;
	vector<glm::mat4>		m4ViewMatrix;

	double leftMargin = 0.05;
	double rightMargin = 0.05;
	double topMargin = 0.05;
	double bottomMargin = 0.05;
	double horizontalSep = 0.02;
	double verticalSep = 0.02;


	unsigned int rows = 3;
	unsigned int columns = 3;

	double mrtQuadWidth = 0; //renderTarget X value, between 0 and 2 for calculation. Normalized to -1 and 1;
	double mrtQuadHeight = 0; //renderTarget Y value, between 0 and 2 for calculation. Normalized to -1 and 1;



	struct Vertex
	{
		glm::vec4 v4Position;
		glm::vec2 v2TexCoord;
		glm::vec4 v4Colour;
		Vertex() {
			v4Position.xyzw = 0.0f;
			v2TexCoord.xy = 0.0f;
			v4Colour.xyzw = 0.0f;
		}
		Vertex(const glm::vec4 &pos, const glm::vec2 &tc, const glm::vec4 &colour) {
			v4Position = pos;
			v2TexCoord = tc;
			v4Colour = colour;
		}
	};

	struct MrtVertex {
		glm::vec3 v3Position;
		glm::vec2 v2TexCoord;
		MrtVertex() {
			v3Position.xyz = 0.0f;
			v2TexCoord.xy = 0.0f;
		}
		MrtVertex(const glm::vec3 &pos, const glm::vec2 &tc) {
			v3Position = pos;
			v2TexCoord = tc;
		}
	};


public:
	MRTExperiment(string name, int duration);
	virtual ~MRTExperiment();

	virtual bool initialize(double currentTime, vector<SDL_Window*> allWindows, vector<SDL_GLContext> allRenderContexts);
	virtual bool run(double currentTime);
	virtual bool cleanup();
	virtual int timeRemaining();
};

