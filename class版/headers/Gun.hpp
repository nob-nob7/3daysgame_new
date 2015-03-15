#pragma once    //ˆê‰ñ‚µ‚©ŒÄ‚Î‚È‚¢
#include "../lib/appEnv.hpp"
#include "macros.hpp"
#include "Point.hpp"
class Gun{
private:
	struct Gun_{
		bool active;
		int direction;
		float x;
		float y;
		float r;
		float speed_x;
		float speed_y;
		Color color;
	};
	
	Gun_ gun[GUN_MAX];

public:
	void Create(AppEnv& env ,Point& point);
	void Move(AppEnv& env);
	void Aim(AppEnv& env , Point& point);
	void Bound();
	void Reset();
	void Draw();
	Gun();

};