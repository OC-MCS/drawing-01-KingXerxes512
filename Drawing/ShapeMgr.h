#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Shape.h"

using namespace std;
using namespace sf;

// finish the ShapeMgr class.

class ShapeMgr
{
private:
	vector<DrawingShape*> shapes;
public:

	// Creates a pointer to a new circle or rectangle and then pushes it to the back of the shapes vector
	void addShape(Vector2f pos, ShapeEnum whichShape, Color color) {
		if (whichShape == CIRCLE) {
			Circle* circlePtr = new Circle(whichShape, color, pos);
			shapes.push_back(circlePtr);
		}
		else {
			Square* squarePtr = new Square(whichShape, color, pos);
			shapes.push_back(squarePtr);
		}
	}
	// Returns a pointer to the list of pointers to shapes
	vector<DrawingShape*>* getPtr() {
		return &shapes;
	}
};
