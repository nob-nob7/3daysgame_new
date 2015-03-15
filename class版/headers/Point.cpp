#include "Point.hpp"
#include "../lib/appEnv.hpp"

Point::Point(){
	snipe = false;
	x = 100;
	y = 0;
	r = 5;
}

bool Point::isSnipe()
{
	return snipe;
}

void Point::Move(float x_,float y_)
{
	x = x_;
	y = y_;
}

void Point::Lock()
{
	snipe = true;
}

void Point::Reset()
{
	snipe = false;
}

void Point::Draw()
{
	if (!snipe)
	{
		drawPoint(x, y, r, Color(1, 0, 0));
	}
}
