#include "Game.h"
#include "GameState.h"

void Game::pushState(GameState* state)
{
	state->initialize();
	states.push(state);
	return;
}

Game::~Game()
{
	while (!states.empty())
	{
		popState();
	}
}

void Game::popState()
{
	delete states.top();
	states.pop();
	return;
}

void Game::changeState(GameState* state)
{
	if (!states.empty())
	{
		popState();
	}
	pushState(state);
	return;
}

GameState* Game::peekState()
{
	if (states.empty())
	{
		return nullptr;	
	}
	return states.top();
}

void Game::gameLoop()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (peekState() == nullptr)
		{
			continue;	
		}
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
			}
			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Z)
				{
					window.setSize(sf::Vector2u(800, 400));
				}
				else if (event.key.code == sf::Keyboard::X)
				{
					window.setPosition(sf::Vector2i(0, 0));
					window.setSize(sf::Vector2u(1200, 600));
				}
				else if (event.key.code == sf::Keyboard::C)
				{
					window.setPosition(sf::Vector2i(0, 0));
					window.setSize(sf::Vector2u(1600, 800));
				}
				peekState()->handleInput();
			}
			}
		}
		peekState()->update(dt);
		window.clear(sf::Color::Black);
		peekState()->draw(dt);
		if (multiplayerBool == false)
		{
			window.display();
		}
	}
}

Game::Game()
{
	windowWidth = 800;
	windowHeight = 400;
	window.create(sf::VideoMode(windowWidth, windowHeight), "Extreme Tetris");
	window.setFramerateLimit(60);

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

void Game::multiplayerStart(bool multiplayer)
{
	multiplayerBool = multiplayer;
}

bool Game::getMultiplayerStart()
{
	return multiplayerBool;
}

void Game::setGameOverBool(bool gameOver)
{
	gameOverBool = gameOver;
}

bool Game::getGameOverBool()
{
	return gameOverBool;
}

sf::Texture Game::setTexture(sf::Texture texture, std::string filePath)
{
	if (!texture.loadFromFile(filePath))
	{
		std::cout << "Error loading texture!";
	}
	return texture;
}

sf::Font Game::setFont(sf::Font fontName, std::string filePath)
{
	if (!fontName.loadFromFile(filePath))
	{
		std::cout << "Error loading font!";
	}
	return fontName;
}

float Game::getWindowWidth()
{
	return windowWidth;
}
float Game::getWindowHeight() 
{
	return windowHeight;
}
