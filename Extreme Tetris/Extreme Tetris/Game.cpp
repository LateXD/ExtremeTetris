#include "Game.h"
#include "GameState.h"

void Game::pushState(GameState* state)
{
	this->states.push(state);

	return;
}

void Game::popState()
{
	delete this->states.top();
	this->states.pop();

	return;
}

void Game::changeState(GameState* state)
{
	if (!this->states.empty())
	{
		popState();
	}

	pushState(state);
	
	return;
}

GameState* Game::peekState()
{
	if (this->states.empty())
	{
		return nullptr;	
	}

	return this->states.top();
	
}

void Game::gameLoop()
{
	sf::Clock clock;

	while (this->window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr)
		{
			continue;	
		}
		peekState()->handleInput();
		peekState()->update(dt);
		this->window.clear(sf::Color::Black);
		peekState()->draw(dt);
		this->window.display();	
	}
}

Game::Game()
{
	
	this->window.create(sf::VideoMode(800, 600), "Extreme Tetris");
	this->window.setFramerateLimit(60);

	//sf::Clock clock;
	//unsigned short frames = 0;

	//if (clock.getElapsedTime().asMicroseconds() >= 500000)
	//{
	//	system("cls");
	//	std::cout << "FPS: " << frames * 2 << "\n";
	//	frames = 0;
	//	clock.restart();
	//}
	//else
	//{
	//	frames++;
	//}
}


Game::~Game()
{
	while (!this->states.empty())
	{
		popState();
	}
}
