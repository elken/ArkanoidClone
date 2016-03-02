#pragma once
#include <SFML/Graphics.hpp>

template <class T>
class BaseShape {
protected:
	T shape;
public:
	BaseShape() {}
	virtual ~BaseShape() {}

	T getShape() const {
		return shape;
	};
	float getX() const {
		return shape.getPosition().x;
	};
	float getY()const {
		return shape.getPosition().y;
	};

	virtual float getLeft() = 0; 
	virtual float getRight() = 0; 
	virtual float getTop() = 0; 
	virtual float getBottom() = 0;

	virtual void update() = 0;
};