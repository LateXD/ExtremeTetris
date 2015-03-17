#include "Blocks.h"

Blocks::Blocks()
{
	randomBlock = rand() % 7 + 1;
	if (randomBlock == 1)
	{
		blockVector = block_O.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 2)
	{
		blockVector = block_Z.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 3)
	{
		blockVector = block_S.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 4)
	{
		blockVector = block_T.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 5)
	{
		blockVector = block_I.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 6)
	{
		blockVector = block_J.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 7)
	{
		blockVector = block_L.spawn(xPos, yPos, blockVector);
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