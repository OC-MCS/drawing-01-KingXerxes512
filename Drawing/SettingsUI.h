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
	SettingsMgr* Mangr;
	Color curColor;
	ShapeEnum curShape;
	CircleShape redButton;
	CircleShape greenButton;
	CircleShape blueButton;
	CircleShape circleButton;
	RectangleShape squareButton;
	RectangleShape buttonArea;
public:
	SettingsUI(SettingsMgr *mgr)
	{
		Mangr = mgr;
		CircleShape c1(25, 30);
		CircleShape c2(20, 30);
		RectangleShape r(Vector2f(40.0f, 40.0f));
		RectangleShape r2(Vector2f(194.0f, 594.0f));
		curColor = mgr->getCurColor();
		curShape = mgr->getCurShape();
		redButton = c1;
		greenButton = c1;
		blueButton = c1;
		circleButton = c2;
		squareButton = r;
		buttonArea = r2;
	}

	void setCurColor(Color col) {
		curColor = col;
	}
	void setCurShape(ShapeEnum shape) {
		curShape = shape;
	}

	void handleMouseUp(Vector2f mouse)
	{
		if (redButton.getGlobalBounds().contains(mouse))
		{
			curColor = Color::Red;
			Mangr->setCurColor(Color::Red);
		}
		if (greenButton.getGlobalBounds().contains(mouse))
		{
			curColor = Color::Green;
			Mangr->setCurColor(Color::Green);
		}
		if (blueButton.getGlobalBounds().contains(mouse))
		{
			curColor = Color::Blue;
			Mangr->setCurColor(Color::Blue);
		}
		if (circleButton.getGlobalBounds().contains(mouse))
		{
			curShape = CIRCLE;
			Mangr->setCurShape(ShapeEnum::CIRCLE);
		}
		if (squareButton.getGlobalBounds().contains(mouse))
		{
			curShape = SQUARE;
			Mangr->setCurShape(ShapeEnum::SQUARE);
		}
	}

	void draw(RenderWindow& win)
	{
		// Draws the button region
		buttonArea.setPosition(Vector2f(3.0f, 3.0f));
		buttonArea.setOutlineColor(Color::Cyan);
		buttonArea.setOutlineThickness(3);
		win.draw(buttonArea);

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
		redButton.setOutlineColor(Color::Red);
		redButton.setOutlineThickness(3);
		redButton.setPosition(Vector2f(x, y));
		greenButton.setOutlineColor(Color::Green);
		greenButton.setOutlineThickness(3);
		greenButton.setPosition(Vector2f(x, y + 80.0f /* Offset */));
		blueButton.setOutlineColor(Color::Blue);
		blueButton.setOutlineThickness(3);
		blueButton.setPosition(Vector2f(x, y + 160.0f /* Offset */));
		win.draw(redButton);
		win.draw(greenButton);
		win.draw(blueButton);

		// Draws the Shape Label
		Font font2;
		if (!font2.loadFromFile("C:\\Windows\\Fonts\\arial.ttf"))
			die("couldn't load font");
		Text shape("Shape Selector", font, 25);
		shape.setFillColor(Color::Black);
		shape.setPosition(Vector2f(15.0f, y + 280.0f /* Offset */));
		win.draw(shape);

		// Draws the Shape Outlines
		circleButton.setPosition(Vector2f(x, y + 360));
		circleButton.setOutlineColor(Color::Black);
		circleButton.setOutlineThickness(3);
		squareButton.setPosition(Vector2f(x, y + 430.0f));
		squareButton.setOutlineColor(Color::Black);
		squareButton.setOutlineThickness(3);
		win.draw(circleButton);
		win.draw(squareButton);

		// =================================================================
		// Fills the color and shape if  they are the curColor or curShape
		// =================================================================
		if (curColor == Color::Red)
		{
			redButton.setFillColor(Color::Red);
			win.draw(redButton);
		}
		else if (curColor == Color::Green)
		{
			greenButton.setFillColor(Color::Green);
			win.draw(greenButton);
		}
		else if (curColor == Color::Blue)
		{
			blueButton.setFillColor(Color::Blue);
			win.draw(blueButton);
		}
		if (curShape == CIRCLE)
		{
			circleButton.setFillColor(Color::Black);
			win.draw(circleButton);
		}
		else if (curShape == SQUARE)
		{
			squareButton.setFillColor(Color::Black);
			win.draw(squareButton);
		}

		// ===============================================================================
		// Detects if mouse is within the button bounds
		// ===============================================================================
		// If mouse is within the circles, they will fill to show you can select them
		if (redButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win))))
		{
			redButton.setFillColor(Color::Red);
			win.draw(redButton);
		}
		else if (!(redButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win)))) && curColor != Color::Red)
		{
			redButton.setFillColor(Color::White);
			win.draw(redButton);
		}

		if (greenButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win))))
		{
			greenButton.setFillColor(Color::Green);
			win.draw(greenButton);
		}
		else if (!(greenButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win)))) && curColor != Color::Green)
		{
			greenButton.setFillColor(Color::White);
			win.draw(greenButton);
		}

		if (blueButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win))))
		{
			blueButton.setFillColor(Color::Blue);
			win.draw(blueButton);
		}
		else if (!(blueButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win)))) && curColor != Color::Blue)
		{
			blueButton.setFillColor(Color::White);
			win.draw(blueButton);
		}

		// If mouse enters the shapes, they will fill to show you can select them
		if (circleButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win))))
		{
			circleButton.setFillColor(Color::Black);
			win.draw(circleButton);
		}
		else if (!(circleButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win)))) && curShape != ShapeEnum::CIRCLE)
		{
			circleButton.setFillColor(Color::White);
			win.draw(circleButton);
		}

		if (squareButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win))))
		{
			squareButton.setFillColor(Color::Black);
			win.draw(squareButton);
		}
		else if (!(squareButton.getGlobalBounds().contains(win.mapPixelToCoords(Mouse::getPosition(win)))) && curShape != ShapeEnum::SQUARE)
		{
			squareButton.setFillColor(Color::White);
			win.draw(squareButton);
		}
	}
};

