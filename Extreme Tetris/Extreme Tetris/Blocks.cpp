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
		blockVector = block_I.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 5)
	{
		blockVector = block_T.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 6)
	{
		blockVector = block_J.spawn(xPos, yPos, blockVector);
	}
	else if (randomBlock == 7)
	{
		blockVector = block_L.spawn(xPos, yPos, blockVector);
	}
	rotation = 0;
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
	rotation++;
	if (randomBlock == 1 || randomBlock == 2 || randomBlock == 3 || randomBlock == 4)
	{
		if (rotation > 1)
		{
			rotation = 0;
		}
	}
	else if (randomBlock == 5 || randomBlock == 6 || randomBlock == 7)
	{
		if (rotation > 3)
		{
			rotation = 0;
		}
	}

	if (randomBlock == 2)
	{
		blockVector = block_Z.rotateBlock_Z(rotation, blockVector);
	}
	else if (randomBlock == 3)
	{
		blockVector = block_S.rotateBlock_S(rotation, blockVector);
	}
	if (randomBlock == 4)
	{
		blockVector = block_I.rotateBlock_I(rotation, blockVector);
	}
	else if (randomBlock == 5)
	{
		blockVector = block_T.rotateBlockC_T(rotation, blockVector);
	}
	else if (randomBlock == 6)
	{
		blockVector = block_J.rotateBlockC_J(rotation, blockVector);
	}
	else if (randomBlock == 7)
	{
		blockVector = block_L.rotateBlockC_L(rotation, blockVector);
	}
}

void Blocks::rotateCounterClockwise()
{
	rotation--;
	if (rotation < 0)
	{
		if (randomBlock == 1 || randomBlock == 2 || randomBlock == 3 || randomBlock == 4)
		{
			rotation = 1;
		}
		else if (randomBlock == 5 || randomBlock == 6 || randomBlock == 7)
		{
			rotation = 3;
		}
	}

	if (randomBlock == 2)
	{
		blockVector = block_Z.rotateBlock_Z(rotation, blockVector);
	}
	else if (randomBlock == 3)
	{
		blockVector = block_S.rotateBlock_S(rotation, blockVector);
	}
	else if (randomBlock == 4)
	{
		blockVector = block_I.rotateBlock_I(rotation, blockVector);
	}
	else if (randomBlock == 5)
	{
		blockVector = block_T.rotateBlockCC_T(rotation, blockVector);
	}
	else if (randomBlock == 6)
	{
		blockVector = block_J.rotateBlockCC_J(rotation, blockVector);
	}
	else if (randomBlock == 7)
	{
		blockVector = block_L.rotateBlockCC_L(rotation, blockVector);
	}
}

std::vector<sf::Sprite> Blocks::getVector()
{
	return blockVector;
}