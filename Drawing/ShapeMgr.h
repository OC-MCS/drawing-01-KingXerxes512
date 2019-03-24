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
	vector<DrawingShape> a;
public:
	ShapeMgr()
	{
		
	}

	void addShape(Vector2f pos, ShapeEnum whichShape, Color color)
	{
		switch (whichShape) {
			case CIRCLE: 
			{
				Circle c;
				c.setColor(color);
				a.push_back(c);
			}
			case SQUARE:
			{
				Square s;
				s.setColor(color);
				a.push_back(s);
			}

		}
	}

	int getVectorSize()
	{
		return a.size();
	}
};
