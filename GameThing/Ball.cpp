#include "Ball.h"


Ball::Ball(float initX, float initY) {
	shape.setPosition(initX, initY);
	shape.setRadius(BALL_RADIUS);
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
}

float Ball::getLeft() {
	return getX() - shape.getRadius();
}

float Ball::getRight() {
	return getX() + shape.getRadius();
}

float Ball::getTop() {
	return getY() - shape.getRadius();
}

sf::Vector2f Ball::getVelocity() const {
	return velocity;
}

void Ball::setX(float x) {
	velocity.x = x;
}

void Ball::setY(float y) {
	velocity.y = y;
}


float Ball::getBottom() {
	return getY() + shape.getRadius();
}

void Ball::update() {
	shape.move(velocity);

	if (getLeft() < 0) {
		velocity.x = BALL_VELOCITY;
	} else if(getRight() > WINDOW_WIDTH) {
		velocity.x = -BALL_VELOCITY;
	}

	if (getTop() < 0) {
		velocity.y = BALL_VELOCITY;
	} else if(getBottom() > WINDOW_HEIGHT) {
		velocity.y = -BALL_VELOCITY;
	}
}
