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
		// Draws the UI background and borders
		RectangleShape Selector(Vector2f(194.0f, 594.0f));
		Selector.setPosition(Vector2f(3.0f, 3.0f));
		Selector.setOutlineColor(Color::Cyan);
		Selector.setOutlineThickness(3);
		win.draw(Selector);

		RectangleShape Drawer(Vector2f(597.0f, 594.0f));
		Drawer.setPosition(Vector2f(200.0f, 3.0f));
		Drawer.setOutlineColor(Color::Cyan);
		Drawer.setOutlineThickness(3);
		win.draw(Drawer);

		// Draws the Color Label
		Font font;
		if (!font.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		Text color("Drawing Color", font, 25);
		color.setFillColor(Color::Black);
		color.setPosition(Vector2f(15.0f, 25.0f));
		win.draw(color);

		// Draws the Color Cirlces
		float x = 70.0f, y = 85.0f;
		CircleShape c1(25, 30);
		c1.setOutlineColor(Color::Red);
		c1.setOutlineThickness(3);
		c1.setPosition(Vector2f(x, y));
		CircleShape c2(25, 30);
		c2.setOutlineColor(Color::Green);
		c2.setOutlineThickness(3);
		c2.setPosition(Vector2f(x, y + 80.0f /* Offset */));
		CircleShape c3(25, 30);
		c3.setOutlineColor(Color::Blue);
		c3.setOutlineThickness(3);
		c3.setPosition(Vector2f(x, y + 160.0f /* Offset */));
		win.draw(c1);
		win.draw(c2);
		win.draw(c3);

		// Draws the Shape Label
		Font font2;
		if (!font2.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		Text shape("Shape Selector", font, 25);
		shape.setFillColor(Color::Black);
		shape.setPosition(Vector2f(15.0f, y + 280.0f /* Offset */));
		win.draw(shape);

		// Draws the Shape Outlines
		CircleShape circleTemplate(20, 30);
		circleTemplate.setPosition(Vector2f(x, y + 360));
		circleTemplate.setOutlineColor(Color::Black);
		circleTemplate.setOutlineThickness(3);
		RectangleShape rectTemplate(Vector2f(40.0f, 40.0f));
		rectTemplate.setPosition(Vector2f(x, y + 430.0f));
		rectTemplate.setOutlineColor(Color::Black);
		rectTemplate.setOutlineThickness(3);
		win.draw(circleTemplate);
		win.draw(rectTemplate);
	}

};
