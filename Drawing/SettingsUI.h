#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SettingsMgr.h"

using namespace std;
using namespace sf;

void die(string msg)
{
	cout << msg << endl;
	exit(-1);
}

class SettingsUI
{
private:

public:
	SettingsUI(SettingsMgr *mgr)
	{

	}
	void handleMouseUp(Vector2f mouse)
	{

	}

	void draw(RenderWindow& win)
	{
		// Draws the editing section
		RectangleShape r(Vector2f(194.0f, 594.0f));
		r.setPosition(Vector2f(3.0f, 3.0f));
		r.setOutlineColor(Color::Cyan);
		r.setOutlineThickness(3);
		win.draw(r);

		// Draws the Color Label
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		Text title("Drawing Color", font, 25);
		title.setFillColor(Color::Black);
		title.setPosition(Vector2f(20.0f, 25.0f));
		win.draw(title);

		// Draws the Color Cirlces
		CircleShape c1(25, 30);
		c1.setOutlineColor(Color::Red);
		c1.setOutlineThickness(2);
		c1.setPosition(Vector2f(60.0f, 75.0f));
		CircleShape c2(25, 30);
		c2.setOutlineColor(Color::Green);
		CircleShape c3(25, 30);
		c3.setOutlineColor(Color::Blue);
		win.draw(c1);

		// Draws the Shape Label



		// Draws the Shape Outlines



	}

};
