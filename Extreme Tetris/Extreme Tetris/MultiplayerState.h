#ifndef MULTIPLAYERSTATE_H
#define MULTIPLAYERSTATE_H

#include "GameState.h"
#include "Blocks.h"
#include "MainMenu.h"
#include <sstream>


class MultiplayerState : public GameState
{
public:
	MultiplayerState(Game* game);
	~MultiplayerState();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
private:

	bool direction = true;
	int blockSize = 20, locationNumber = 0, positionCounter = 0, vectorSize = 4, pointsCounter = 0, points = 0, randomBlock = rand() % 7 + 1, randomBlock2, pointsMover = 10;
	Blocks* block;
	sf::Clock clock;
	sf::Sprite frame, frame2, pointsFrame, pointsFrame2;
	sf::Text pointsText, pointsText2;
	sf::Font font;
	std::stringstream ss;
	sf::Texture frameTexture, pointsFrameTexture;
	std::vector<sf::Sprite> spriteVector;
	std::vector<Blocks*>blockVector;
};
#endif;