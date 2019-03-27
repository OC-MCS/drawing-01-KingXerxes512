#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

class DrawingShape	// Abstract class for Circle and Square
{
private:
	ShapeEnum shape;
	Color color;
	Vector2f pos;
public:
	// function is overridden by the Circle and Square class functions
	virtual void draw(RenderWindow& win) = 0;

	DrawingShape(ShapeEnum shape, Color color, Vector2f pos) {
		this->shape = shape;
		this->color = color;
		this->pos = pos;
	}
	// Sets cur color
	void setColor(Color col) {
		color = col;
	}
	// Returns cur color
	Color getColor() {
		return color;
	}
	// Sets cur shape
	void setShape(ShapeEnum newShape) {
		shape = newShape;
	}
	// Returns cur shape
	ShapeEnum getShape() {
		return shape;
	}
	// Sets position
	void setPos(Vector2f Pos) {
		pos = Pos;
	}
	// Returns position
	Vector2f getPos() {
		return pos;
	}
};

class Circle : public DrawingShape
{
private:
	CircleShape circle;
public:
	// Calls DrawingShape constructor
	Circle(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos) {}
	// Gives attributes to the CircleShape
	void draw(RenderWindow& win) {
		circle.setRadius(20.0f);
		circle.setFillColor(getColor());
		circle.setOutlineColor(getColor());
		circle.setPosition(getPos());
		win.draw(circle);
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape r;
public:
	// Calls DrawingShape constructor
	Square(ShapeEnum shape, Color color, Vector2f pos) : DrawingShape(shape, color, pos) {}
	// Gives attributes to the RectangleShape
	void draw(RenderWindow& win) {
		r.setSize(Vector2f(20.0f, 20.0f));
		r.setFillColor(getColor());
		r.setOutlineColor(getColor());
		r.setPosition(getPos());
		win.draw(r);
	}
};

