#pragma once

class Point{
private:
	bool snipe;
	float x;
	float y;
	float r;
	

public:
	bool isSnipe();
	void Move(float,float);
	void Lock();
	void Reset();
	void Draw();
	Point();
};