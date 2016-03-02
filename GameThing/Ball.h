#pragma once
#include "constants.h"
#include "Util.hpp"
#include "BaseShape.hpp"

class Ball : public BaseShape<sf::CircleShape> {
	sf::Vector2f velocity{ -BALL_VELOCITY, -BALL_VELOCITY };

public:
	Ball(float initX, float initY);
	~Ball() {}
	void update() override;
	float getLeft() override;
	float getRight() override;
	float getTop() override;
	float getBottom() override;
	sf::Vector2f getVelocity() const;
	void setX(float x);
	void setY(float y);
};
