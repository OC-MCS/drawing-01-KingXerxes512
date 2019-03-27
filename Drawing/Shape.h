#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;
using namespace sf;

// finish this code; add functions, classes, data as needed

// DrawingShape should be an abstract base class 
// for Circle and Square
class DrawingShape 
{
private:
	ShapeEnum shape;
	Color color;
	Vector2f pos;
public:
	virtual void draw() {}

	void setColor(Color col) {
		color = col;
	}
	Color getColor() {
		return color;
	}
	void setShape(ShapeEnum newShape) {
		shape = newShape;
	}
	ShapeEnum getShape() {
		return shape;
	}
	void setPos(Vector2f Pos) {
		pos = Pos;
	}
	Vector2f getPos() {
		return pos;
	}
};

class Circle : public DrawingShape
{
private:
	CircleShape c;
public:
	Circle() {
		setShape(CIRCLE);
	}
	void draw() {
		
	}
};

class Square : public DrawingShape
{
private:
	RectangleShape r;
public:
	Square() {
		setShape(SQUARE);
	}
	void draw() {

	}
};

