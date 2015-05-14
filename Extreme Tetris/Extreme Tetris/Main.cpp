#include "Game.h"
#include "MainMenu.h"

int main()
{
	srand(time(NULL));
	Game game;
	game.pushState(new MainMenu(&game));
	game.gameLoop();
	return 0;
}