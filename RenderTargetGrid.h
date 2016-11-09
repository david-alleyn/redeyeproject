#pragma once

#define GLM_FORCE_SWIZZLE
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <glm\mat4x4.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <vector>

#define GLEW_STATIC
#include <GL/glew.h>

#include "FBO.h"

using namespace std;

class RenderTargetGrid
{
	const double NDCWIDTH = 2;
	const double NDCHEIGHT = 2;

	unsigned int rows;
	unsigned int columns;

	double mrtQuadWidth;
	double mrtQuadHeight;

	bool fboBound;
	int currentBoundFbo;

	unsigned int shader;
	vector<unsigned int> vaos;
	vector<FBO*> fbos;
	unsigned int tbo;
	unsigned int offsetDataTex;
	unsigned int mrtQuadVBO;
	unsigned int mrtQuadIBO;

	vector<unsigned int> drawWidth;
	vector<unsigned int> drawHeight;

	vector<unsigned int> screenWidth;
	vector<unsigned int> screenHeight;

	/*double leftMargin = 0.00;
	double rightMargin = 0.00;
	double topMargin = 0.00;
	double bottomMargin = 0.00;
	double horizontalSep = 0.00;
	double verticalSep = 0.00;*/

public:
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

	unsigned int getViewportWidth(unsigned int vaoIndex);
	unsigned int getViewportHeight(unsigned int vaoIndex);

	RenderTargetGrid(unsigned int shader, unsigned int rows = 1, unsigned columns = 1, double leftMarginPercentage = 0.01, double rightMarginPercentage = 0.01, double topMarginPercentage = 0.01, double bottomMarginPercentage = 0.01, double horizontalSeperationPercentage = 0.01, double verticalSeperationPercentage = 0.01);
	void addRenderTargetVAO(unsigned int width, unsigned int height);
	void resizeFrameBuffer(unsigned int vaoIndex, unsigned int width, unsigned int height);
	void bindRenderTargetVAO(unsigned int vaoIndex);
	void bindRenderTargetFBO(unsigned int fbo);
	void unbindRenderTargetFBO();
	void draw();
	double getAspectRatio(unsigned int vaoIndex);

	~RenderTargetGrid();
};

