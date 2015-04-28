#ifndef GAME_H
#define GAME_H

//#include <SFML/Graphics/RenderWindow.hpp>
//#include <SFML/Graphics/Texture.hpp>
//#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <stack>
#include <time.h>
#include <ctime>

class GameState;

class Game
{

private:
	float windowWidth, windowHeight;
public:

	std::stack<GameState*> states;

	sf::RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	GameState* peekState();

	float getWindowWidth();
	float getWindowHeight();

	void gameLoop();

	Game();
	~Game();
};
#endif;
