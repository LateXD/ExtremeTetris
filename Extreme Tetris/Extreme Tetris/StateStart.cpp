#include "StateStart.h"
#include "GameState.h"

StateStart::StateStart(Game* game) 
{
	this->game = game;
}

void StateStart::draw(const float dt)
{
	this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);

	return;
}

void StateStart::handleInput()
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
			//TODO:: IF YOU WANT TO RESIZE THE WINDOW

		/*case sf::Event::Resized:
		{

		}*/
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->window.close();
				break;
			}
		default:
			break;
		}
		}
	}
}
void StateStart::update(const float dt)
{

}
StateStart::~StateStart()
{
}
