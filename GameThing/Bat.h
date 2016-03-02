#pragma once
#include <SFML/Graphics.hpp>
#include "BaseShape.hpp"

class Bat : public BaseShape<sf::RectangleShape> {
	sf::Vector2f velocity;

	public:
		Bat(float initX, float initY);
		~Bat() {}
		void update() override;
		sf::Vector2f getvelocity() const;
		float getLeft() override;
		float getRight() override;
		float getTop() override;
		float getBottom() override;
};
