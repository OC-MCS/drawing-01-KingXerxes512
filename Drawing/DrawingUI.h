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
	RectangleShape drawingArea;
public:
	DrawingUI(Vector2f p)
	{
		RectangleShape r3(Vector2f(597.0f, 594.0f));
		drawingArea = r3;
	}

	void draw(RenderWindow& win, ShapeMgr *mgr)
	{
		// Draws the drawing background
		drawingArea.setPosition(Vector2f(200.0f, 3.0f));
		drawingArea.setOutlineColor(Color::Cyan);
		drawingArea.setOutlineThickness(3);
		win.draw(drawingArea);
	}
	
	bool isMouseInCanvas(Vector2f mousePos)
	{
		if (drawingArea.getGlobalBounds().contains(mousePos)) {
			return true;
		}
		else {
			return false;
		}
	}

};

