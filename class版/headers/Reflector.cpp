#include "Reflector.hpp"
#include "../lib/appEnv.hpp"
#include "Shot.hpp"
#include "macros.hpp"
#include <fstream>


Reflector::Reflector()
{
	std::ifstream points("src/headers/points.txt");
	/*	for (int i = 0; i < 10; i++)
		{
		points >> x[i];
		}

		for (int i = 0; i < 10; i++)
		{
		points >> y[i];
		}*/
	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
		{
			points >> x[i];
		}
		else { points >> y[i - 10]; }

	}
}

void Reflector::Draw()
{
	for (int i = 0; i < 10; i++){

		drawPoint(x[i], y[i], 10, Color(1, 0, 0));
	}
}

void Reflector::Reflect(Shot& shot)
{
	for (int i = 0; i < SHOT_MAX; i++)
	{
		if (x[0] == shot.shot[i].x && y[0] == shot.shot[i].y){
			shot.shot[i].direction = 3;
		}
		if (x[1] == shot.shot[i].x && y[1] == shot.shot[i].y){
			shot.shot[i].direction = 3;
		}
		if (x[2] == shot.shot[i].x && y[2] == shot.shot[i].y){
			shot.shot[i].direction = 2;
		}
		if (x[3] == shot.shot[i].x && y[3] == shot.shot[i].y){
			shot.shot[i].direction = 2;
		}
		if (x[4] == shot.shot[i].x && y[4] == shot.shot[i].y){
			shot.shot[i].direction = 4;
		}
		if (x[5] == shot.shot[i].x && y[5] == shot.shot[i].y){
			shot.shot[i].direction = 1;
		}
		if (x[6] == shot.shot[i].x && y[6] == shot.shot[i].y){
			shot.shot[i].direction = 3;
		}
		if (x[7] == shot.shot[i].x && y[7] == shot.shot[i].y){
			shot.shot[i].direction = 2;
		}
		if (x[8] == shot.shot[i].x && y[8] == shot.shot[i].y){
			shot.shot[i].direction = 3;
		}
		if (x[9] == shot.shot[i].x && y[9] == shot.shot[i].y){
			shot.shot[i].direction = 1;
		}
	}
}


