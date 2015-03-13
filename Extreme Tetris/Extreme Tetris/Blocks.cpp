#include "Blocks.h"

Blocks::Blocks()
{
	blockVector = block_O.spawn(xPos, yPos, blockVector);
}

Blocks::~Blocks()
{
}

void Blocks::moveLeft()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(-20, 0);
	}
}

void Blocks::moveRight()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(20, 0);
	}
}

void Blocks::moveDown()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(0, 20);
	}
}

void Blocks::rotateClockwise()
{

}

void Blocks::rotateCounterClockwise()
{

}

std::vector<sf::Sprite> Blocks::getVector()
{
	return blockVector;
}