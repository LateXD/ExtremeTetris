#include "MultiplayerState.h"


MultiplayerState::MultiplayerState(Game* game)
{
	this->game = game;
}

void MultiplayerState::draw(const float dt)
{

}

void MultiplayerState::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->pushState(new MainMenu(this->game));
				std::cout << "Back to main menu\n";
				return;
			}
		}
		default:
			break;
		}

	}
}

void MultiplayerState::update(const float dt)
{

}


MultiplayerState::~MultiplayerState()
{
}
