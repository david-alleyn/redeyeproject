#include "wx/wxprec.h"
#include "MovingCircle.h"


bool MovingCircle::textureGenerated = false;
unsigned int MovingCircle::texture = 0;

MovingCircle::MovingCircle(glm::vec2 size, glm::vec4 color, glm::vec2 position, double speed, unsigned int shader) : MovingObject(size, position, speed)
{
	this->color = color;
	this->shader = shader;

	if (!textureGenerated) {

		// CREATE CIRCLE TEXTURE DATA
		int texDimensions = 256; //must be factor of 2
		double radius = ((double)texDimensions) / 2.0f;
		glm::vec4 *texData = new glm::vec4[texDimensions * texDimensions];
		for (int i = 0; i < texDimensions * texDimensions; i += texDimensions)
		{
			for (int j = 0; j < texDimensions; ++j)
			{
				double xNorm = (i / texDimensions) + 1;
				double yNorm = (j + 1);
				//if (j % 2 == 0)
				//{
				//	texData[i + j] = glm::vec4(0, 0, 0, 1); //
				//}
				//else
				//{
				double distanceFromCenter = sqrt(pow((double)xNorm - (double)radius, 2) + pow((double)yNorm - (double)radius, 2));

				if (distanceFromCenter <= radius) {
					texData[i + j] = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
				}
				else {
					texData[i + j] = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
				}
				//}


			}
		}

		// CREATE TEXTURE HANDLE, BIND THE HANDLE, AND BUFFER THE TEXTURE
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA32F, 256, 256, 0, GL_RGBA, GL_FLOAT, texData);

		textureGenerated = true;

		// SET TEXTURE FILTERING OPTIONS
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glBindTexture(GL_TEXTURE_2D, 0);


		//// set the texture to use slot 0 in the shader
		//GLuint texUniformID = glGetUniformLocation(basicShader, "diffuseTexture");
		//glUniform1i(texUniformID, 0);

		// cleanup Texture Data:
		delete[] texData;
		texData = nullptr;
	}

	if (!sharedBuffer) {
		// now create a quad:
		Vertex circleQuadVertices[4];
		circleQuadVertices[0].v4Position = glm::vec4(-0.1, 0, -0.1, 1);
		circleQuadVertices[0].v2TexCoord = glm::vec2(0, 0);
		circleQuadVertices[0].v4Colour = color;
		circleQuadVertices[1].v4Position = glm::vec4(0.1, 0, -0.1, 1);
		circleQuadVertices[1].v2TexCoord = glm::vec2(1, 0);
		circleQuadVertices[1].v4Colour = color;
		circleQuadVertices[2].v4Position = glm::vec4(0.1, 0, 0.1, 1);
		circleQuadVertices[2].v2TexCoord = glm::vec2(1, 1);
		circleQuadVertices[2].v4Colour = color;
		circleQuadVertices[3].v4Position = glm::vec4(-0.1, 0, 0.1, 1);
		circleQuadVertices[3].v2TexCoord = glm::vec2(0, 1);
		circleQuadVertices[3].v4Colour = color;

		unsigned int circleQuadIndices[6] = {
			3,1,0,
			3,2,1
		};


		// CREATE Vertex buffers / index buffers for circleQuad

		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ibo);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

		glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex), circleQuadVertices, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6 * sizeof(unsigned int), circleQuadIndices, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}

}

MovingCircle::MovingCircle(glm::vec2 size, glm::vec4 color, glm::vec2 position, double speed, unsigned int shader, unsigned int vbo, unsigned int ibo) : MovingObject(size, position, speed) {
	this->color = color;
	this->shader = shader;	
	this->vbo = vbo;
	this->ibo = ibo;
	this->sharedBuffer = true;
}


MovingCircle::~MovingCircle()
{
}

glm::vec4 MovingCircle::getColor()
{
	return color;
}

unsigned int MovingCircle::getVBOHandle() {
	return vbo;
}

unsigned int MovingCircle::getIBOHandle() {
	return ibo;
}

void MovingCircle::addVao() {
	unsigned int dotVao;
	glGenVertexArrays(1, &dotVao);

	vaos.push_back(dotVao);
	glBindVertexArray(dotVao);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 16);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), ((char*)0) + 24);

	glBindVertexArray(0);
}

void MovingCircle::bindVao(unsigned int vaoIndex) {
	glUseProgram(shader);
	GLuint texUniformID = glGetUniformLocation(shader, "diffuseTexture");

	glActiveTexture(GL_TEXTURE0);
	glUniform1i(texUniformID, 0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glBindVertexArray(vaos[vaoIndex]);
}

void MovingCircle::draw(glm::mat4 relativeMatrix, glm::mat4 projectionMatrix, glm::mat4 viewMatrix) {
	GLuint ProjectionID = glGetUniformLocation(shader, "Projection");
	GLuint ViewID = glGetUniformLocation(shader, "View");
	GLuint ModelID = glGetUniformLocation(shader, "Model");

	glUniformMatrix4fv(ProjectionID, 1, false, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(ViewID, 1, false, glm::value_ptr(viewMatrix));

	double x = getPosition().x;
	double y = getPosition().y;
	double width = getSize().x;
	double height = getSize().y;
	glm::mat4 dotTransform = glm::translate(relativeMatrix, glm::vec3(x, 0.0f, y));
	dotTransform = glm::scale(dotTransform, glm::vec3(width, 0.0f, height));

	glUniformMatrix4fv(ModelID, 1, false, glm::value_ptr(dotTransform));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
