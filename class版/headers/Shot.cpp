#include "Shot.hpp"
#include "Point.hpp"
#include "../lib/random.hpp"
#include <ctime>

Shot::Shot(){
	Random random;
	random.setSeed(time(nullptr));

	for (int i = 0; i < SHOT_MAX; i++){
		shot[i].active = false;
		shot[i].x = 0;
		shot[i].y = 0;
		shot[i].r = 10;
		shot[i].direction = D_RIGHT;
		shot[i].speed_x = 4;
		shot[i].speed_y = 4;
		shot[i].color.red() = random.fromFirstToLast(0.0f, 1.0f);
		shot[i].color.green() = random.fromFirstToLast(0.0f, 1.0f);
		shot[i].color.blue() = random.fromFirstToLast(0.0f, 1.0f);
	}
}

void Shot::Create(AppEnv& env, Point& point)
{
	if (env.isPushButton(Mouse::LEFT))
	{
		for (int i = 0; i < SHOT_MAX; i++){
			point.Lock();
			if (!shot[i].active)
			{
				shot[i].active = true;
				break;
			}
		}
	}
}

void Shot::Move(AppEnv& env)
{
	for (int i = 0; i < SHOT_MAX; i++){
		if (shot[i].active && shot[i].direction == D_UP)
		{
			shot[i].y += shot[i].speed_y;
		}
		if (shot[i].active && shot[i].direction == D_DOWN)
		{
			shot[i].y -= shot[i].speed_y;
		}
		if (shot[i].active && shot[i].direction == D_LEFT)
		{
			shot[i].x -= shot[i].speed_x;
		}
		if (shot[i].active && shot[i].direction == D_RIGHT)
		{
			shot[i].x += shot[i].speed_x;
		}

		if (shot[i].x == 0 && shot[i].y == 220)
		{
			shot[i].direction = 3;
		}
		if (shot[i].x == -100 && shot[i].y == 220)
		{
			shot[i].direction = 3;
		}
		if (shot[i].x == -220 && shot[i].y == 220)
		{
			shot[i].direction = 2;
		}
		if (shot[i].x == -220 && shot[i].y == 0)
		{
			shot[i].direction = 2;
		}
		if (shot[i].x == -220 && shot[i].y == -220)
		{
			shot[i].direction = 4;
		}
		if (shot[i].x == 220 && shot[i].y == -220)
		{
			shot[i].direction = 1;
		}
		if (shot[i].x == 220 && shot[i].y == 220)
		{
			shot[i].direction = 3;
		}
		if (shot[i].x == 100 && shot[i].y == 220)
		{
			shot[i].direction = 2;
		}
		if (shot[i].x == 100 && shot[i].y == -100)
		{
			shot[i].direction = 3;
		}
		if (shot[i].x == -100 && shot[i].y == -100)
		{
			shot[i].direction = 1;
		}

	}
}

void Shot::Aim(AppEnv& env, Point& point)
{
	if (!point.isSnipe())
	{
		for (int i = 0; i < SHOT_MAX; i++){
			if (env.isPushKey(GLFW_KEY_UP))
			{
				point.Move(0, 100);
				shot[i].direction = D_UP;

			}

			if (env.isPushKey(GLFW_KEY_DOWN))
			{
				point.Move(0, -100);

				shot[i].direction = D_DOWN;

			}

			if (env.isPushKey(GLFW_KEY_LEFT))
			{
				point.Move(-100, 0);
				shot[i].direction = D_LEFT;

			}

			if (env.isPushKey(GLFW_KEY_RIGHT))
			{
				point.Move(100, 0);
				shot[i].direction = D_RIGHT;
			}
			
		}
	}
}

void Shot::Reflect()
{
	for (int i = 0; i < SHOT_MAX; i++){
		if ((shot[i].x >= WIDTH / 2) || (shot[i].x <= -WIDTH / 2))
		{
			shot[i].speed_x *= -1;
		}
		if ((shot[i].y >= HEIGHT / 2) || (shot[i].y <= -HEIGHT / 2))
		{
			shot[i].speed_y *= -1;
		}
	}
}

void Shot::Reset()
{
	for (int i = 0; i < SHOT_MAX; ++i){
		shot[i].active = false;
		shot[i].x = 0;
		shot[i].y = 0;
	}
}

void Shot::Draw()
{
	for (int i = 0; i < SHOT_MAX; i++){
		if (shot[i].active){
			drawFillCircle(shot[i].x, shot[i].y, shot[i].r, shot[i].r, 100, shot[i].color);
		}
	}
}