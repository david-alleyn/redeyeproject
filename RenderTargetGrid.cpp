#include "wx/wxprec.h"
#include "RenderTargetGrid.h"

unsigned int RenderTargetGrid::getViewportWidth(unsigned int vaoIndex) {
	return drawWidth[vaoIndex];
}

unsigned int RenderTargetGrid::getViewportHeight(unsigned int vaoIndex) {
	return drawHeight[vaoIndex];
}

RenderTargetGrid::RenderTargetGrid(unsigned int shader, unsigned int rows, unsigned columns, double leftMarginPercentage, double rightMarginPercentage, double topMarginPercentage, double bottomMarginPercentage, double horizontalSeperationPercentage, double verticalSeperationPercentage) {

	this->shader = shader;
	this->rows = rows;
	this->columns = columns;

	fboBound = false;
	currentBoundFbo = 0;

	//All relevant screen space margins and seperations converted from percentages to Normalized Device Coordinate compatible quantities.
	double leftMarginNDC = NDCWIDTH * leftMarginPercentage;
	double rightMarginNDC = NDCWIDTH * rightMarginPercentage;
	double topMarginNDC = NDCHEIGHT * topMarginPercentage;
	double bottomMarginNDC = NDCHEIGHT * bottomMarginPercentage;
	double vertSeperationNDC = NDCHEIGHT * verticalSeperationPercentage;
	double horizSeperationNDC = NDCWIDTH * horizontalSeperationPercentage;

	double totalHorizontalSepNDC = horizSeperationNDC * ((double)columns - 1.0);
	double totalVerticalSepNDC = vertSeperationNDC * ((double)rows - 1.0);

	//determine the dimension of the render target's quad by subtracting all of the space designed for margins and seperations
	//
	mrtQuadWidth = ((NDCWIDTH - leftMarginNDC - rightMarginNDC - totalHorizontalSepNDC)) / columns;
	mrtQuadHeight = ((NDCHEIGHT - topMarginNDC - bottomMarginNDC - totalVerticalSepNDC)) / rows;

	vector<glm::vec4> offsets;

	for (unsigned int row = 0; row < rows; row++) {
		for (unsigned int column = 0; column < columns; column++) {

			double xOffset = leftMarginNDC + (mrtQuadWidth * (double)column) + (horizSeperationNDC * (double)column);
			double yOffset = bottomMarginNDC + (mrtQuadHeight * (double)row) + (vertSeperationNDC * (double)row);

			offsets.push_back(glm::vec4(xOffset, yOffset, 0.0f, 0.0f));
		}
	}

	//Send the position offsets for all the render targets to the GPU as a special "texture buffer" object.
	glGenBuffers(1, &tbo);
	glBindBuffer(GL_TEXTURE_BUFFER, tbo);
	glBufferData(GL_TEXTURE_BUFFER, sizeof(glm::vec4) * offsets.size(), &offsets[0], GL_STATIC_DRAW);

	glGenTextures(1, &offsetDataTex);
	glBindTexture(GL_TEXTURE_BUFFER, offsetDataTex);
	glTexBuffer(GL_TEXTURE_BUFFER, GL_RGBA32F, tbo);

	//Construct a quad for use as a render target using the calculated mrtQuad values but offset for Normalized Device Coordinates
	double mrtQuadWidthNDC = mrtQuadWidth - 1.0;
	double mrtQuadHeightNDC = mrtQuadHeight - 1.0;

	std::vector<MrtVertex> mrtQuadVertices;
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(-1, -1, 0), glm::vec2(0, 0)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(mrtQuadWidthNDC, -1, 0), glm::vec2(1, 0)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(mrtQuadWidthNDC, mrtQuadHeightNDC, 0), glm::vec2(1, 1)));
	mrtQuadVertices.push_back(MrtVertex(glm::vec3(-1, mrtQuadHeightNDC, 0), glm::vec2(0, 1)));


	// Create the indices for how the 
	std::vector<unsigned int> mrtQuadIndices;
	mrtQuadIndices.push_back(0); mrtQuadIndices.push_back(1); mrtQuadIndices.push_back(2);
	mrtQuadIndices.push_back(2); mrtQuadIndices.push_back(3); mrtQuadIndices.push_back(0);


	// CREATE Vertex buffers / index buffers for mrtQuad
	glGenBuffers(1, &mrtQuadVBO);
	glBindBuffer(GL_ARRAY_BUFFER, mrtQuadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(MrtVertex) * 4, &mrtQuadVertices[0], GL_STATIC_DRAW);
	glGenBuffers(1, &mrtQuadIBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mrtQuadIBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * 6, &mrtQuadIndices[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
	glEnableVertexAttribArray(1); glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));
}

void RenderTargetGrid::addRenderTargetVAO(unsigned int width, unsigned int height) {
	unsigned int mrtWidth = (mrtQuadWidth / NDCWIDTH) * width;
	unsigned int mrtHeight = (mrtQuadHeight / NDCHEIGHT) * height;
	
	unsigned int mrtVao;
	glGenVertexArrays(1, &mrtVao);

	drawWidth.push_back(mrtWidth);
	drawHeight.push_back(mrtHeight);

	screenWidth.push_back(width);
	screenHeight.push_back(height);

	// Setup VAOs and Vertex Attribs for mrtQuad:
	vaos.push_back(mrtVao);
	fbos.push_back(new FBO(mrtWidth, mrtHeight));
	

	glBindVertexArray(mrtVao);

	glBindBuffer(GL_ARRAY_BUFFER, mrtQuadVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mrtQuadIBO);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(MrtVertex), (void*)sizeof(glm::vec3));

	//glBindVertexArray(0);
}

void RenderTargetGrid::resizeFrameBuffer(unsigned int vaoIndex, unsigned int width, unsigned int height) {
	fbos[vaoIndex]->resize(width, height);
}

void RenderTargetGrid::bindRenderTargetVAO(unsigned int vaoIndex) {
	glViewport(0, 0, screenWidth[vaoIndex], screenHeight[vaoIndex]);
	glUseProgram(shader);

	glActiveTexture(GL_TEXTURE0 + 1);
	glBindTexture(GL_TEXTURE_2D, fbos[vaoIndex]->getRGBATexture());
	GLuint tColor = glGetUniformLocation(shader, "texture_color");
	glUniform1i(tColor, 1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_BUFFER, offsetDataTex);
	glUniform1i(glGetUniformLocation(shader, "offsets"), 0);

	glBindVertexArray(vaos[vaoIndex]);
}

void RenderTargetGrid::bindRenderTargetFBO(unsigned int fbo) {
	glViewport(0, 0, drawWidth[fbo], drawHeight[fbo]);
	fbos[fbo]->bind();
	fboBound = true;
	currentBoundFbo = fbo;
}

void RenderTargetGrid::unbindRenderTargetFBO() {
	if (fboBound) {
		fbos[currentBoundFbo]->unbind();
	}
}

void RenderTargetGrid::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDrawElementsInstanced(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0, rows * columns);
}

double RenderTargetGrid::getAspectRatio(unsigned int vaoIndex) {
	return (double) drawWidth[vaoIndex] / (double) drawHeight[vaoIndex];
}

RenderTargetGrid::~RenderTargetGrid()
{
	for (int i = 0; i < fbos.size(); i++) {
		if (fbos[i] != NULL) {
			delete fbos[i];
			fbos[i] = NULL;
		}
	}

	glDeleteBuffers(1, &mrtQuadVBO);
	glDeleteBuffers(1, &mrtQuadIBO);
	glDeleteBuffers(1, &tbo);
	glDeleteTextures(1, &offsetDataTex);
	
	for (int i = 0; i < vaos.size(); i++) {
		glDeleteVertexArrays(1, &vaos[0]);
	}

}
