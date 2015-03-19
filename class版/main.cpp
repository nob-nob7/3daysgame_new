//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "headers\macros.hpp"
#include "headers\Shot.hpp"
#include "headers\Point.hpp"

// 
// メインプログラム
// 

void Draw()
{
	int b_point_x[] = { 0, -100, -220, -220, -220, 220, 220, 100, 100, -100 };
	int b_point_y[] = { 220, 220, 220, 0, -220, -220, 220, 220, -100, -100 };

	for (int i = 0; i < SHOT_MAX; i++){

		drawPoint(b_point_x[i], b_point_y[i], 10, Color(1, 0, 0));
	}
}


int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Shot shot;
	Point point;
	while (env.isOpen()) {
		shot.Aim(env, point);

		shot.Create(env, point);
	

		shot.Move(env);

		shot.Reflect();



		if (env.isPushKey('R'))
		{
			shot.Reset();
			point.Reset();
		}
		env.setupDraw();

		Draw();
		shot.Draw();
		point.Draw();
		env.update();
	}
}
