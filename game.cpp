#include"game.h"

void CGame::play_game()
{
	int number = 0;
	std::cin >> number;
	
	switch (number)
	{
	case 1:
		football.play();
		break;
	case 2:
		dudagi.Play();
		break;
	default:
		break;
	}
}