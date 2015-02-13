#include "GameState.h"


GameState::GameState()
{
	initialized = false;
}


// Tyhjä metodi joka voidaan ylikirjoittaa perivässä
// statessa, jos staten tarvitsee ladata resursseja.
void GameState::onInitialize()
{

}

void GameState::initialize() 
{
	if (initialized)
	{
		return;
	}

	onInitialize();

	initialized = true;
}

GameState::~GameState()
{
}
