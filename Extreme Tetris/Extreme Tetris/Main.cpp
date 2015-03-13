#include "Game.h"
#include "MainMenu.h"

int main()
{
	Game game;
	game.pushState(new MainMenu(&game));
	game.gameLoop();							//gameLoop() metodissa pyörii itse peli
												//ja toimii ns. main.cpp:nä

	return 0;
}