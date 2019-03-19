#pragma once
#include <SFML/Graphics.hpp>
#include "ShapeMgr.h"
#include <iostream>

using namespace std;
using namespace sf;

// finish this code; add functions, data as needed

class DrawingUI
{
private:

public:
	DrawingUI(Vector2f p)
	{
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		return false; // just to make it compile
	}

};

