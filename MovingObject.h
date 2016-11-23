#pragma once

#define GLM_FORCE_SWIZZLE
#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <glm\mat4x4.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <random>

using namespace std;

class MovingObject
{
protected:
	static int maxId;
	int id;
	glm::vec2 size;
	glm::vec2 position;
	glm::vec2 deltaPosition;
	double leftbound;
	double rightbound;
	double topbound;
	double bottombound;
	double speed;

	std::uniform_real_distribution<double> unif;
	std::default_random_engine re;

protected:
	MovingObject();
	MovingObject(glm::vec2 size, glm::vec2 position, double speed);


public:

	~MovingObject();

	glm::vec2 getSize();
	glm::vec2 getPosition();
	glm::vec2 getDeltaPosition();
	double getSpeed();
	unsigned int getShader();
	double getLeftBound();
	double getRightBound();
	double getTopBound();
	double getBottomBound();

	void setBounds(double leftbound, double rightbound, double topbound, double bottombound);

	void setLeftBound(double leftbound);
	void setRightBound(double rightbound);
	void setTopBound(double topbound);
	void setBottomBound(double bottombound);

	void setSize(glm::vec2 size);
	void setPosition(glm::vec2 position);
	void setDeltaPosition(glm::vec2 deltaPosition);
	void setSpeed(double speed);

	virtual void randomMovement();
	virtual void addVao() = 0;
	virtual void bindVao(unsigned int vao) = 0;
	virtual void draw(glm::mat4 relativeMatrix, glm::mat4 projectionMatrix, glm::mat4 viewMatrix) = 0;


};

