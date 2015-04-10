#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"
#include "Blocks.h"
#include "MainMenu.h"
#include <sstream>

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
	int blockSize = 20, locationNumber = 0, positionCounter = 0, vectorSize = 4, pointsCounter = 0, points = 0;
	sf::Clock clock;
	sf::Sprite frame;
	sf::Text pointsText;
	sf::Font font;
	std::stringstream ss;
	sf::Texture frameTexture;
	std::vector<sf::Sprite> spriteVector;
	std::vector<Blocks*>blockVector;
};
#endif;

