#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"
#include "Blocks.h"
#include "MainMenu.h"

class StateStart : public GameState
{
public:
	StateStart(Game* game);
	~StateStart();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void makeField();
	void printField();
	
private:
	//sf::View view;
	int xPos = 3, yPos = 0, number = 0, xSize = 12, ySize = 20, counter = 0;
	Blocks block;
	sf::Clock clock;
	sf::Sprite frame;
	sf::Texture frameTexture;
	std::vector<int>fieldVector;
	std::vector<sf::Sprite> vector;
	std::vector<Blocks*>blockVector;
};
#endif;

