//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "headers\macros.hpp"
#include "headers\Gun.hpp"
#include "headers\Point.hpp"

// 
// メインプログラム
// 

void Draw()
{
	int b_point_x[] = { 0, -100, -220, -220, -220, 220, 220, 100, 100, -100 };
	int b_point_y[] = { 220, 220, 220, 0, -220, -220, 220, 220, -100, -100 };

	for (int i = 0; i < GUN_MAX; i++){

		drawPoint(b_point_x[i], b_point_y[i], 10, Color(1, 0, 0));
	}
}


int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Gun gun;
	Point point;
	while (env.isOpen()) {
		gun.Aim(env, point);

		gun.Create(env, point);
	

		gun.Move(env);

		gun.Bound();



		if (env.isPushKey('R'))
		{
			gun.Reset();
			point.Reset();
		}
		env.setupDraw();

		Draw();
		gun.Draw();
		point.Draw();
		env.update();
	}
}
