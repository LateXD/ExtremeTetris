#include "PlayerState.h"

// Hops between SingleplayerState and MultiplayerState resulting in two players on screen at the same time

PlayerState::PlayerState(Game* game)
{
	this->game = game;
}

PlayerState::~PlayerState()
{
}

void PlayerState::onInitialize()
{
	game->window.setView(game->view);
	player1 = new SingleplayerState(game);
	player2 = new MultiplayerState(game);
	game->initializePlayers(player1);
	game->initializePlayers(player2);
	game->multiplayerStart(true);
}

void PlayerState::draw(const float dt)
{
	game->window.clear();
	player1->draw(dt);
	player2->draw(dt);
	game->window.display();
}

void PlayerState::handleInput()
{
	player1->handleInput();
	player2->handleInput();
}

void PlayerState::update(const float dt)
{
	if (game->getGameOverBool() == true)
	{
		game->multiplayerStart(false);
		game->setGameOverBool(false);
		delete player1;
		delete player2;
		game->popState();
		return;
	}
	player1->update(dt);
	player2->update(dt);
}