#pragma once    //ˆê‰ñ‚µ‚©ŒÄ‚Î‚È‚¢
#include "../lib/appEnv.hpp"
#include "macros.hpp"
#include "Point.hpp"
class Shot{
private:
	struct Shot_{
		bool active;
		int direction;
		float x;
		float y;
		float r;
		float speed_x;
		float speed_y;
		Color color;
	};
	
	

public:
	void Create(AppEnv& env ,Point& point);
	void Move(AppEnv& env);
	void Aim(AppEnv& env , Point& point);
	void Reflect();
	void Reset();
	void Draw();
	Shot_ shot[SHOT_MAX];
	Shot();

};