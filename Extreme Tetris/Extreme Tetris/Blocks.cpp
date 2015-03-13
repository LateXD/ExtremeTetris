#include "Blocks.h"

Blocks::Blocks()
{
	Block_O block_O;
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector = block_O.spawn(i, xPos, yPos, blockVector);
	}

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
	xPos--;
}

void Blocks::moveRight()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(20, 0);
	}
	xPos++;
}

void Blocks::moveDown()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(0, 20);
	}
	yPos++;
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