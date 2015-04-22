#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"
#include "Blocks.h"
#include "MainMenu.h"
#include <sstream>
#include <list>

class StateStart : public GameState
{
public:
	StateStart(Game* game);
	~StateStart();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	void rowClearing();

private:
	//sf::View view;
	bool direction = true, newBlock = true, collision = false, clearRow = false;
	int blockSize = 20, locationNumber = 0, positionCounter = 0, vectorSize = 4, pointsCounter = 0, points = 0, randomBlock = rand() % 7 + 1, randomBlock2, pointsMover = 10, rowCounter = 0, rowNumber = 0, rowPoints = 0, level = 0;
	Blocks* block;
	sf::Clock clock;
	sf::Sprite frame, pointsFrame, bg;
	sf::Text pointsText;
	sf::Font font;
	std::stringstream ss;
	sf::Texture frameTexture, pointsFrameTexture, bgTexture;
	std::vector<sf::Sprite> spriteVector, allSprites;
	std::vector<Blocks*>blockVector;
	std::list <sf::Sprite> a;
};
#endif;
