#include "StateStart.h"
#include "GameState.h"
#include "MainMenu.h"

StateStart::StateStart(Game* game) 
{
	this->game = game;
	if (!frameTexture.loadFromFile("..\\Graphics\\Frame.png"))
	{
		std::cout << "Can't load texture!";
	}
	frame.setTexture(frameTexture);
	frame.setColor(sf::Color(100, 255, 100));
}

void StateStart::draw(const float dt)
{
	// Jos halutaan käyttää toista näkymää (View), tulee
	// vanha ensiksi ottaa talteen, jotta siihen voidaan palata.

	//this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);
	vector = blockPointer->getVector();
	for (int i = 0; i < 4; i++)
	{
		game->window.draw(vector[i]);
		game->window.draw(frame);
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
			else if (event.key.code == sf::Keyboard::Left && xPos != 0)
			{
				blockPointer->moveLeft();
				xPos--;
			}
			else if (event.key.code == sf::Keyboard::Right && xPos != 8)
			{
				blockPointer->moveRight();
				xPos++;
			}
			else if (event.key.code == sf::Keyboard::Down && yPos != 16)
			{
				blockPointer->moveDown();
				yPos++;
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
	if (yPos == 16)
	{
		blockPointer = new Blocks;
		xPos = 3;
		yPos = 0;
	}
	if (clock.getElapsedTime().asMicroseconds() >= 500000 && yPos != 16)
	{
		yPos++;
		blockPointer->moveDown();
		clock.restart();
	}
}

StateStart::~StateStart()
{
}