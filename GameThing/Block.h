#pragma once
#include "BaseShape.hpp"
#include "Util.hpp"

class Block : public BaseShape<sf::RectangleShape> {
	bool destroyed = false;

public:
	Block(float initX, float initY);
	float getLeft() override;
	float getRight() override;
	float getTop() override;
	float getBottom() override;
	bool isDestroyed() const;
	void destroy();
	void update() override;
};
