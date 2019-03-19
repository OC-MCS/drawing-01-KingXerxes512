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
	virtual void draw()
	{
	}
	//virtual struct getFileRecord();
};

class Circle : public DrawingShape
{
private:
	CircleShape c;
public:
	Circle()
	{

	}
	void draw()
	{

	}
	//struct getFileRecord();
};

class Square : public DrawingShape
{
private:
	RectangleShape r;
public:
	Square()
	{

	}
	void draw()
	{
		
	}
	//struct getFileRecord();
};

