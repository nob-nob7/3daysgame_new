//
// アプリ雛形
//

#include "lib/defines.hpp"
#include "lib/appEnv.hpp"
#include "lib/random.hpp"
#include "headers\macros.hpp"
#include "headers\Shot.hpp"
#include "headers\Point.hpp"
#include "headers\Reflector.hpp"

// 
// メインプログラム
// 


int main() {
	AppEnv env(Window::WIDTH, Window::HEIGHT, false, false);

	Shot shot;
	Point point;
	Reflector reflect;
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

		reflect.Draw();
		reflect.Reflect(shot);
		shot.Draw();
		point.Draw();
		env.update();
	}
}
