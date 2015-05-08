#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H
#include "MultiplayerState.h"

class PlayerState : public GameState
{
public:
	PlayerState(Game *game);
	~PlayerState();
	void draw(const float dt);
	void update(const float dt);
	void handleInput();

private:
	GameState *player1;
	GameState *player2;
};

#endif