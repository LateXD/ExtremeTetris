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
	
private:
	//sf::View view;
	int blockSize = 20, number = 0, positionCounter = 0, vectorSize = 4;
	sf::Clock clock;
	sf::Sprite frame;
	sf::Texture frameTexture;
	std::vector<int>fieldVector;
	std::vector<sf::Sprite> vector;
	std::vector<Blocks*>blockVector;
};
#endif;

