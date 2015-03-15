#include "Gun.hpp"
#include "Point.hpp"
#include "../lib/random.hpp"
#include <ctime>

Gun::Gun(){
	Random random;
	random.setSeed(time(nullptr));

	for (int i = 0; i < GUN_MAX; i++){
		gun[i].active = false;
		gun[i].x = 0;
		gun[i].y = 0;
		gun[i].r = 10;
		gun[i].direction = 4;
		gun[i].speed_x = 4;
		gun[i].speed_y = 4;
		gun[i].color.red() = random.fromFirstToLast(0.0f, 1.0f);
		gun[i].color.green() = random.fromFirstToLast(0.0f, 1.0f);
		gun[i].color.blue() = random.fromFirstToLast(0.0f, 1.0f);
	}
}

void Gun::Create(AppEnv& env, Point& point)
{
	if (env.isPushButton(Mouse::LEFT))
	{
		for (int i = 0; i < GUN_MAX; i++){
			point.Lock();
			if (!gun[i].active)
			{
				gun[i].active = true;
				break;
			}
		}
	}
}

void Gun::Move(AppEnv& env)
{
	for (int i = 0; i < GUN_MAX; i++){
		if (gun[i].active && gun[i].direction == 1)
		{
			gun[i].y += gun[i].speed_y;
		}
		if (gun[i].active && gun[i].direction == 2)
		{
			gun[i].y -= gun[i].speed_y;
		}
		if (gun[i].active && gun[i].direction == 3)
		{
			gun[i].x -= gun[i].speed_x;
		}
		if (gun[i].active && gun[i].direction == 4)
		{
			gun[i].x += gun[i].speed_x;
		}

		if (gun[i].x == 0 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -100 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -220 && gun[i].y == 220)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == -220 && gun[i].y == 0)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == -220 && gun[i].y == -220)
		{
			gun[i].direction = 4;
		}
		if (gun[i].x == 220 && gun[i].y == -220)
		{
			gun[i].direction = 1;
		}
		if (gun[i].x == 220 && gun[i].y == 220)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == 100 && gun[i].y == 220)
		{
			gun[i].direction = 2;
		}
		if (gun[i].x == 100 && gun[i].y == -100)
		{
			gun[i].direction = 3;
		}
		if (gun[i].x == -100 && gun[i].y == -100)
		{
			gun[i].direction = 1;
		}

	}
}

void Gun::Aim(AppEnv& env, Point& point)
{
	if (!point.isSnipe())
	{
		for (int i = 0; i < GUN_MAX; i++){
			if (env.isPushKey(GLFW_KEY_UP))
			{
				point.Move(0, 100);
				gun[i].direction = 1;

			}

			if (env.isPushKey(GLFW_KEY_DOWN))
			{
				point.Move(0, -100);

				gun[i].direction = 2;

			}

			if (env.isPushKey(GLFW_KEY_LEFT))
			{
				point.Move(-100, 0);
				gun[i].direction = 3;

			}

			if (env.isPushKey(GLFW_KEY_RIGHT))
			{
				point.Move(100, 0);
				gun[i].direction = 4;
			}
			
		}
	}
}

void Gun::Bound()
{
	for (int i = 0; i < GUN_MAX; i++){
		if ((gun[i].x >= WIDTH / 2) || (gun[i].x <= -WIDTH / 2))
		{
			gun[i].speed_x *= -1;
		}
		if ((gun[i].y >= HEIGHT / 2) || (gun[i].y <= -HEIGHT / 2))
		{
			gun[i].speed_y *= -1;
		}
	}
}

void Gun::Reset()
{
	for (int i = 0; i < GUN_MAX; ++i){
		gun[i].active = false;
		gun[i].x = 0;
		gun[i].y = 0;
	}
}

void Gun::Draw()
{
	for (int i = 0; i < GUN_MAX; i++){
		if (gun[i].active){
			drawFillCircle(gun[i].x, gun[i].y, gun[i].r, gun[i].r, 100, gun[i].color);
		}
	}
}