#ifndef BLOCKS_H
#define BLOCKS_H
#include "Block_O.h"
#include "Block_Z.h"
#include "Block_S.h"
#include "Block_T.h"
#include "Block_I.h"
#include "Block_J.h"
#include "Block_L.h"

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
	int randomBlock, vectorSize = 4, xPos = 0, yPos = 0, rotation = 0;
	std::vector<sf::Sprite>blockVector;
	Block_O block_O;
	Block_Z block_Z;
	Block_S block_S;
	Block_T block_T;
	Block_I block_I;
	Block_J block_J;
	Block_L block_L;
};

#endif