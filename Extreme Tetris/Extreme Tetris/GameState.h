#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "Game.h"

class GameState		//GameState manageri
{
private:
	bool initialized;
protected:
	virtual void onInitialize();
public:

	Game* game;

	virtual void draw(const float dt) = 0;
	virtual void update(const float dt) = 0;
	virtual void handleInput() = 0;

	// Kutsutaan kun gamestate vaihdetaan aktiiviseksi.
	void initialize();

	GameState();
	~GameState();
};
#endif;

