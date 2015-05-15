#include "Game.h"
#include "GameState.h"

Game::Game()
{
	windowWidth = 400;
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

Game::~Game()
{
	while (!states.empty())
	{
		popState();
	}
}

void Game::pushState(GameState* state)
{
	state->initialize();
	states.push(state);
	return;
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

void Game::initializePlayers(GameState* state)
{
	state->initialize();
	return;
}

void Game::gameLoop()
{
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Time elapsed = clock.restart();
		float dt = elapsed.asSeconds();

		if (multiplayerBool == false)
		{
			if (window.getSize() != sf::Vector2u(400, 400) && window.getSize() != sf::Vector2u(600, 600) && window.getSize() != sf::Vector2u(800, 800))
			{
				window.setSize(sf::Vector2u(400, 400));
				view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
				window.setView(view);
			}
		}
		else if (multiplayerBool == true)
		{
			if (window.getSize() != sf::Vector2u(800, 400) && window.getSize() != sf::Vector2u(1200, 600) && window.getSize() != sf::Vector2u(1600, 800))
			{
				window.setSize(sf::Vector2u(800, 400));
				view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
				window.setView(view);
			}
		}

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
					if (multiplayerBool == true)
					{
						window.setSize(sf::Vector2u(800, 400));
					}
					else
					{
						window.setSize(sf::Vector2u(400, 400));
					}
				}
				else if (event.key.code == sf::Keyboard::X)
				{
					if (multiplayerBool == true)
					{
						window.setSize(sf::Vector2u(1200, 600));
					}
					else
					{
						window.setSize(sf::Vector2u(600, 600));
					}
					window.setPosition(sf::Vector2i(0, 0));
				}
				else if (event.key.code == sf::Keyboard::C)
				{
					if (multiplayerBool == true)
					{
						window.setSize(sf::Vector2u(1600, 800));
					}
					else
					{
						window.setSize(sf::Vector2u(800, 800));
					}
					window.setPosition(sf::Vector2i(0, 0));
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
