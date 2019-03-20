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
	Color curColor;
	ShapeEnum curShape;
public:
	SettingsMgr(Color startingColor, ShapeEnum startingShape)
	{
		curColor = startingColor;
		curShape = startingShape;
	}

	Color getCurColor()
	{
		return curColor;
	}

	void setCurColor(Color newColor)
	{
		curColor = newColor;
	}

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

	void setCurShape(ShapeEnum newShape)
	{
		curShape = newShape;
	}

};
