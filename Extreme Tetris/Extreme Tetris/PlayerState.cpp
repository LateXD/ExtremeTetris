#include "PlayerState.h"


PlayerState::PlayerState(Game* game)
{
	this->game = game;
	player1 = new StateStart(game);
	player2 = new MultiplayerState(game);
	game->multiplayerStart(true);
}


PlayerState::~PlayerState()
{
}

void PlayerState::update(const float dt)
{
	player1->update(dt);
	player2->update(dt);
}

void PlayerState::handleInput()
{
	player1->handleInput();
	player2->handleInput();
}

void PlayerState::draw(const float dt)
{
	game->window.clear();
	player1->draw(dt);
	player2->draw(dt);
	game->window.display();
}