#include "Block.h"
#include "constants.h"

Block::Block(float initX, float initY) {
	shape.setPosition(initX, initY);
	shape.setSize({ BLOCK_WIDTH, BLOCK_HEIGHT });
	shape.setFillColor(sf::Color::Yellow);
	shape.setOrigin(BLOCK_WIDTH / 2, BLOCK_HEIGHT / 2);
}

float Block::getLeft() {
	return getX() - shape.getSize().x / 2;
}

float Block::getRight() {
	return getX() + shape.getSize().x / 2;
}

float Block::getTop() {
	return getY() - shape.getSize().y / 2;
}

bool Block::isDestroyed() const {
	return destroyed;
}

void Block::destroy() {
	destroyed = true;
}

void Block::update() {}

float Block::getBottom() {
	return getY() + shape.getSize().y / 2;
}
