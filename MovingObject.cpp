#include "wx/wxprec.h"
#include "MovingObject.h"


int MovingObject::maxId = 0;

MovingObject::MovingObject()
{
	id = maxId;
	maxId++;
	this->size = glm::vec3(1.0f);
	this->position = glm::vec3(0.0f);
	this->speed = 0.5;
	this->leftbound = -2.0;
	this->rightbound = 2.0;
	this->topbound = 2.0;
	this->bottombound = -2.0;

	unif = std::uniform_real_distribution<double>(0.0, 1.0);
	re = std::default_random_engine(id);
}


MovingObject::MovingObject(glm::vec2 size, glm::vec2 position, double speed) : MovingObject()
{
	this->size = size;
	this->position = position;
	this->speed = speed;
}

MovingObject::~MovingObject()
{
}

glm::vec2 MovingObject::getSize()
{
	return size;
}

glm::vec2 MovingObject::getPosition()
{
	return position;
}

glm::vec2 MovingObject::getDeltaPosition()
{
	return deltaPosition;
}

double MovingObject::getSpeed()
{
	return speed;
}

double MovingObject::getLeftBound() {
	return leftbound;
}

double MovingObject::getRightBound() {
	return rightbound;
}

double MovingObject::getTopBound() {
	return topbound;
}

double MovingObject::getBottomBound() {
	return bottombound;
}

void MovingObject::setBounds(double leftbound, double rightbound, double topbound, double bottombound) {
	this->leftbound = leftbound;
	this->rightbound = rightbound;
	this->topbound = topbound;
	this->bottombound = bottombound;
}

void MovingObject::setLeftBound(double leftbound) {
	this->leftbound = leftbound;
}

void MovingObject::setRightBound(double rightbound) {
	this->rightbound = rightbound;
}

void MovingObject::setTopBound(double topbound) {
	this->topbound = topbound;
}

void MovingObject::setBottomBound(double bottombound) {
	this->bottombound = bottombound;
}

void MovingObject::setSize(glm::vec2 size) {
	this->size = size;
}

void MovingObject::setPosition(glm::vec2 position) {
	this->position = position;
}

void MovingObject::setDeltaPosition(glm::vec2 deltaPosition) {
	this->deltaPosition = deltaPosition;
}

void MovingObject::setSpeed(double speed) {
	this->speed = speed;
}

void MovingObject::randomMovement() {

	do {
		if (unif(re) > 0.8) {
			deltaPosition.x = (unif(re) < 0.5 ? speed : 0);
			if (unif(re) < 0.5) deltaPosition.x = -deltaPosition.x;
		}

		if (unif(re) > 0.8) {
			deltaPosition.y = (unif(re) < 0.5 ? speed : 0);
			if (unif(re) < 0.5) deltaPosition.y = -deltaPosition.y;
		}
	} while (deltaPosition.x == 0 && deltaPosition.y == 0);

	if (position.x + deltaPosition.x < leftbound || position.x + deltaPosition.x > rightbound) {
		deltaPosition.x = 0;
	}
	if (position.y + deltaPosition.y < bottombound || position.y + deltaPosition.y > topbound) {
		deltaPosition.y = 0;
	}

	position.x += deltaPosition.x;
	position.y += deltaPosition.y;
}
