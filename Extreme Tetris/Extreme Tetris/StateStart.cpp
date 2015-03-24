#include "StateStart.h"

StateStart::StateStart(Game* game) 
{
	this->game = game;
	if (!frameTexture.loadFromFile("..\\Graphics\\Frame.png"))
	{
		std::cout << "Can't load texture!";
	}
	frame.setTexture(frameTexture);
	frame.setColor(sf::Color(100, 255, 100));
	blockVector.push_back(new Blocks);
}

void StateStart::draw(const float dt)
{
	// Jos halutaan käyttää toista näkymää (View), tulee
	// vanha ensiksi ottaa talteen, jotta siihen voidaan palata.

	//this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);
	game->window.draw(frame);
	for (int i = 0; i < blockVector.size(); i++)
	{
		vector = blockVector[i]->getVector();
		for (int i = 0; i < 4; i++)
		{
			game->window.draw(vector[i]);
		}
	}
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
			else if (event.key.code == sf::Keyboard::Left && vector[0].getPosition().x - 20 > 0)
			{
				blockVector[number]->moveLeft();
				xPos--;
			}
			else if (event.key.code == sf::Keyboard::Right && vector[0].getPosition().x + 20 < 180) 
			{
				blockVector[number]->moveRight();
				xPos++;
			}
			else if (event.key.code == sf::Keyboard::Down && yPos != 15)
			{
				blockVector[number]->moveDown();
				yPos++;
			}
			else if (event.key.code == sf::Keyboard::M)
			{
				blockVector[number]->rotateClockwise();
			}
			else if (event.key.code == sf::Keyboard::N)
			{
				blockVector[number]->rotateCounterClockwise();
			}
		default:
			break;
		}
		}
	}
}

void StateStart::update(const float dt)
{
	if (yPos == 15)
	{
		blockVector.push_back(new Blocks);
		number++;
		xPos = 3;
		yPos = 0;
	}
	if (clock.getElapsedTime().asMicroseconds() >= 500000 && yPos != 15)
	{
		yPos++;
		blockVector[number]->moveDown();
		clock.restart();
	}
}

StateStart::~StateStart()
{
}