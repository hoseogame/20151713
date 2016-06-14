#include"game.h"

int main()
{
	CGame Game;
	std::cout << "1. 풋볼게임" << std::endl;
	std::cout << "2. 두더지게임" << std::endl;

	Game.play_game();
}