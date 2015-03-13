#include "StateStart.h"
#include "GameState.h"
#include "MainMenu.h"

StateStart::StateStart(Game* game) 
{
	this->game = game;
}

void StateStart::draw(const float dt)
{
	// Jos halutaan käyttää toista näkymää (View), tulee
	// vanha ensiksi ottaa talteen, jotta siihen voidaan palata.

	//this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);
	vector = block.getVector();
	for (int i = 0; i < 4; i++)
	{
		game->window.draw(vector[i]);
	}
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
				this->game->pushState(new MainMenu(this->game));
				std::cout << "Back to main menu\n";
				return;
			}
			else if (event.key.code == sf::Keyboard::Left)
			{
				block.moveLeft();
			}
			else if (event.key.code == sf::Keyboard::Right)
			{
				block.moveRight();
			}
			else if (event.key.code == sf::Keyboard::Down)
			{
				block.moveDown();
			}
			else if (event.key.code == sf::Keyboard::M)
			{
				
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