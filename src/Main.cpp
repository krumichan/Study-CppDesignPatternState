#include "entity/player/Player.h"

#include <iostream>
#include <thread>
#include <chrono>

int main(void)
{
	//　ディレイの間隔
	std::chrono::milliseconds duration(100);

	Player player;

	while (1)
	{
		//　player活性化
		player.Update();

		//　現在の位置を出力
		std::cout << "現在位置：(" << player.x << "," << player.y << ")" << std::endl;

		//　負荷を下げる為のディレイ
		std::this_thread::sleep_for(duration);
	}

	return 0;
}
