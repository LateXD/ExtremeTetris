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
public:

	std::stack<GameState*> states;

	sf::RenderWindow window;

	void pushState(GameState* state);
	void popState();
	void changeState(GameState* state);
	void initializePlayers(GameState* state);
	GameState* peekState();

	float getWindowWidth();
	float getWindowHeight();

	void gameLoop();
	void multiplayerStart(bool multiplayer);
	bool getMultiplayerStart();
	void setGameOverBool(bool gameOver);
	bool getGameOverBool();
	sf::Texture setTexture(sf::Texture texture, std::string filePath);
	sf::Font setFont(sf::Font fontName, std::string filePath);
	sf::View view;

	Game();
	~Game();

private:
	bool multiplayerBool = false, gameOverBool = false;
	float windowWidth, windowHeight;
	sf::Event event;

};
#endif;
