#pragma once
#include "MovingObject.h"

#define GLEW_STATIC
#include <GL/glew.h>


class MovingCircle :
	public MovingObject
{
	glm::vec4 color;

	unsigned int shader;
	vector<unsigned int> vaos;

	//texture only needs to be made once
	static unsigned int texture;
	static bool textureGenerated;

	bool sharedBuffer; //set to true when re-using buffers from another MovingCircle
	unsigned int vbo;
	unsigned int ibo;

public:

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

	MovingCircle(glm::vec2 size, glm::vec4 color, glm::vec2 position, double speed, unsigned int shader);
	MovingCircle(glm::vec2 size, glm::vec4 color, glm::vec2 position, double speed, unsigned int shader, unsigned int vbo, unsigned int ibo);
	~MovingCircle();

	glm::vec4 getColor();
	unsigned int getVBOHandle();
	unsigned int getIBOHandle();

	virtual void addVao();
	virtual void bindVao(unsigned int vaoIndex);
	virtual void draw(glm::mat4 relativeMatrix, glm::mat4 projectionMatrix, glm::mat4 viewMatrix);

};

