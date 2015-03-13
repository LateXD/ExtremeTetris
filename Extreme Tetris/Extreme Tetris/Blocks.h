#ifndef BLOCKS_H
#define BLOCKS_H
#include "Block_O.h"

class Blocks
{
public:
	Blocks();
	~Blocks();
	void moveLeft();
	void moveRight();
	void moveDown();
	void rotateClockwise();
	void rotateCounterClockwise();
	std::vector<sf::Sprite> getVector();
	Game* game;

private:
	int randomBlock = 0, vectorSize = 4, xPos = 0, yPos = 0;
	std::vector<sf::Sprite>blockVector;
};

#endif