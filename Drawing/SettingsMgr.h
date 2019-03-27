#pragma once
#include <typeinfo>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

enum ShapeEnum { CIRCLE, SQUARE };

class SettingsMgr
{
private:
	// Will hold the current color in use
	Color curColor;
	// Will hold the current shape in use
	ShapeEnum curShape;
public:
	// Constructor which initializes default shape and color if save file not found
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		curColor = startingColor;
		curShape = startingShape;
	}

	// Returns current color
	Color getCurColor()
	{
		return curColor;
	}

	// Sets current color
	void setCurColor(Color newColor)
	{
		curColor = newColor;
	}

	// Returns current shape
	ShapeEnum getCurShape()
	{
		switch (curShape)
		{
		case CIRCLE:
			return CIRCLE;
		case SQUARE:
			return SQUARE;
		}
	}

	// Sets current shape
	void setCurShape(ShapeEnum newShape)
	{
		curShape = newShape;
	}
};
