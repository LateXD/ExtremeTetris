#include "OptionsState.h"
#include "MainMenu.h"


OptionsState::OptionsState(Game* game)
{
	this->game = game;
}

void OptionsState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);

	return;
}

void OptionsState::handleInput()
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
				this->game->pushState(new MainMenu(this->game));
				std::cout << "Back to main menu\n";
				return;
			}
		default:
			break;
		}
		}
	}
}

void OptionsState::update(const float dt)
{

}

OptionsState::~OptionsState()
{
}
