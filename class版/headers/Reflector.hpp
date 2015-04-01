#pragma once
#include "Shot.hpp"

class Reflector
{
private:
	float x[10];
	float y[10];

public:
	void Draw();
	Reflector();
	void Reflect(Shot&);
};

