#pragma once

#include <glm\vec2.hpp>
#include <glm\vec3.hpp>
#include <glm\vec4.hpp>
#include <random>

class MovingObject
{
private:
	static int maxId;

	int id;
	glm::vec2 size;
	glm::vec4 color;
	glm::vec2 position;
	glm::vec2 deltaPosition;
	double leftbound;
	double rightbound;
	double topbound;
	double bottombound;


	double speed;

	std::uniform_real_distribution<double> unif;
	std::default_random_engine re;


public:

	MovingObject();
	MovingObject(glm::vec2 size, glm::vec4 color, glm::vec2 position, double speed, double leftbound, double rightbound, double topbound, double bottombound);
	~MovingObject();

	glm::vec2 getSize();
	glm::vec4 getColor();
	glm::vec2 getPosition();
	glm::vec2 getDeltaPosition();
	double getSpeed();

	void setSize(glm::vec2 size);
	void setColor(glm::vec4 color);
	void setPosition(glm::vec2 position);
	void setDeltaPosition(glm::vec2 deltaPosition);
	void setSpeed(double speed);

	void randomMovement();


};

