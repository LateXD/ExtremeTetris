#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState		//GameState manageri
{
public:

	Game* game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;

	GameState();
	~GameState();

};
#endif;

