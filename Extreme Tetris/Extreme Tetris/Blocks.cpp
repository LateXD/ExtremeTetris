#include "Blocks.h"

Blocks::Blocks(int rb)
{
	if (rb == 1)
	{
		blockVector = block_O.spawn(blockVector);
	}
	else if (rb == 2)
	{
		blockVector = block_Z.spawn(blockVector);
	}
	else if (rb == 3)
	{
		blockVector = block_S.spawn(blockVector);
	}
	else if (rb == 4)
	{
		blockVector = block_I.spawn(blockVector);
	}
	else if (rb == 5)
	{
		blockVector = block_T.spawn(blockVector);
	}
	else if (rb == 6)
	{
		blockVector = block_J.spawn(blockVector);
	}
	else if (rb == 7)
	{
		blockVector = block_L.spawn(blockVector);
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
		blockVector[i].move(-blockSize, 0);
	}
}

void Blocks::moveRight()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(blockSize, 0);
	}
}

void Blocks::moveDown()
{
	for (int i = 0; i < vectorSize; i++)
	{
		blockVector[i].move(0, 20);
	}
}

void Blocks::rotateClockwise(int rb)
{
	rotation++;
	if (rb == 1 || rb == 2 || rb == 3 || rb == 4)
	{
		if (rotation > 1)
		{
			rotation = 0;
		}
	}
	else if (rb == 5 || rb == 6 || rb == 7)
	{
		if (rotation > 3)
		{
			rotation = 0;
		}
	}

	if (rb == 2)
	{
		blockVector = block_Z.rotateBlock_Z(rotation, blockVector);
	}
	else if (rb == 3)
	{
		blockVector = block_S.rotateBlock_S(rotation, blockVector);
	}
	if (rb == 4)
	{
		blockVector = block_I.rotateBlock_I(rotation, blockVector);
	}
	else if (rb == 5)
	{
		blockVector = block_T.rotateBlockC_T(rotation, blockVector);
	}
	else if (rb == 6)
	{
		blockVector = block_J.rotateBlockC_J(rotation, blockVector);
	}
	else if (rb == 7)
	{
		blockVector = block_L.rotateBlockC_L(rotation, blockVector);
	}
}

void Blocks::rotateCounterClockwise(int rb)
{
	rotation--;
	if (rotation < 0)
	{
		if (rb == 1 || rb == 2 || rb == 3 || rb == 4)
		{
			rotation = 1;
		}
		else if (rb == 5 || rb == 6 || rb == 7)
		{
			rotation = 3;
		}
	}

	if (rb == 2)
	{
		blockVector = block_Z.rotateBlock_Z(rotation, blockVector);
	}
	else if (rb == 3)
	{
		blockVector = block_S.rotateBlock_S(rotation, blockVector);
	}
	else if (rb == 4)
	{
		blockVector = block_I.rotateBlock_I(rotation, blockVector);
	}
	else if (rb == 5)
	{
		blockVector = block_T.rotateBlockCC_T(rotation, blockVector);
	}
	else if (rb == 6)
	{
		blockVector = block_J.rotateBlockCC_J(rotation, blockVector);
	}
	else if (rb == 7)
	{
		blockVector = block_L.rotateBlockCC_L(rotation, blockVector);
	}
}

void Blocks::nextBlock(bool direction)
{
	if (direction == true)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			blockVector[i].move(blockSize * 10, blockSize);
		}
	}
	else
	{
		for (int i = 0; i < vectorSize; i++)
		{
			blockVector[i].move(-blockSize * 10, -blockSize);
		}
	}
}

std::vector<sf::Sprite>Blocks::getVector()
{
	return blockVector;
}