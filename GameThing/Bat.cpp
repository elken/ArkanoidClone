#include "Bat.h"
#include "constants.h"

Bat::Bat(float initX, float initY) {
	shape.setPosition(initX, initY);
	shape.setSize({ BLOCK_WIDTH, BLOCK_HEIGHT });
	shape.setFillColor(sf::Color::Red);
	shape.setOrigin(BLOCK_WIDTH / 2, BLOCK_HEIGHT / 2);
}

void Bat::update() {
	shape.move(velocity);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && getLeft() > 0) {
		velocity.x = -BAT_VELOCITY;
	} else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && getRight() < WINDOW_WIDTH) {
		velocity.x = BAT_VELOCITY;
	} else {
		velocity.x = 0;
	}
}

float Bat::getLeft() {
	return getX() - shape.getSize().x / 2;
}

float Bat::getRight() {
	return getX() + shape.getSize().x / 2;
}

float Bat::getTop() {
	return getY() - shape.getSize().y / 2;
}

float Bat::getBottom() {
	return getY() + shape.getSize().y / 2;
}

sf::Vector2f Bat::getvelocity() const {
	return velocity;
}
