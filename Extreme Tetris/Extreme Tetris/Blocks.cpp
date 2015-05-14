#include "Blocks.h"

Blocks::Blocks(int rb)
{
	switch (rb)
	{
	case 1:
		currentBlockSprites = block_O.spawn(currentBlockSprites);
		break;
	case 2:
		currentBlockSprites = block_Z.spawn(currentBlockSprites);
		break;
	case 3:
		currentBlockSprites = block_S.spawn(currentBlockSprites);
		break;
	case 4:
		currentBlockSprites = block_I.spawn(currentBlockSprites);
		break;
	case 5:
		currentBlockSprites = block_T.spawn(currentBlockSprites);
		break;
	case 6:
		currentBlockSprites = block_J.spawn(currentBlockSprites);
		break;
	case 7:
		currentBlockSprites = block_L.spawn(currentBlockSprites);
		break;
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
		currentBlockSprites[i].move(-blockSize, 0);
	}
}

void Blocks::moveRight()
{
	for (int i = 0; i < vectorSize; i++)
	{
		currentBlockSprites[i].move(blockSize, 0);
	}
}

void Blocks::moveDown()
{
	for (int i = 0; i < vectorSize; i++)
	{
		currentBlockSprites[i].move(0, 20);
	}
}

void Blocks::rotateClockwise(int rb, std::vector<sf::Sprite> spritesVector)
{
	// Rotates a block and if rotating it results in a situation where the block is inside a wall it rotates it back
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

	switch (rb)
	{
	case 2:
		currentBlockSprites = block_Z.rotateBlock_Z(rotation, currentBlockSprites);
		break;
	case 3:
		currentBlockSprites = block_S.rotateBlock_S(rotation, currentBlockSprites);
		break;
	case 4:
		currentBlockSprites = block_I.rotateBlock_I(rotation, currentBlockSprites);
		break;
	case 5:
		currentBlockSprites = block_T.rotateBlockC_T(rotation, currentBlockSprites);
		break;
	case 6:
		currentBlockSprites = block_J.rotateBlockC_J(rotation, currentBlockSprites);
		break;
	case 7:
		currentBlockSprites = block_L.rotateBlockC_L(rotation, currentBlockSprites);
		break;
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (currentBlockSprites[i].getPosition().x == 0 || currentBlockSprites[i].getPosition().x == blockSize * 11 || currentBlockSprites[i].getPosition().x == blockSize * 28 || currentBlockSprites[i].getPosition().x == blockSize * 39 || currentBlockSprites[i].getPosition().y == blockSize * 19)
		{
			rotateCounterClockwise(rb, spritesVector);
			break;
		}
		for (int j = 0; j < spritesVector.size() - vectorSize; j++)
		{
			if (currentBlockSprites[i].getPosition().x == spritesVector[j].getPosition().x && currentBlockSprites[i].getPosition().y == spritesVector[j].getPosition().y)
			{
				rotateCounterClockwise(rb, spritesVector);
				break;
			}
		}
	}
}

void Blocks::rotateCounterClockwise(int rb, std::vector<sf::Sprite> spritesVector)
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

	switch (rb)
	{
	case 2:
		currentBlockSprites = block_Z.rotateBlock_Z(rotation, currentBlockSprites);
		break;
	case 3:
		currentBlockSprites = block_S.rotateBlock_S(rotation, currentBlockSprites);
		break;
	case 4:
		currentBlockSprites = block_I.rotateBlock_I(rotation, currentBlockSprites);
		break;
	case 5:
		currentBlockSprites = block_T.rotateBlockCC_T(rotation, currentBlockSprites);
		break;
	case 6:
		currentBlockSprites = block_J.rotateBlockCC_J(rotation, currentBlockSprites);
		break;
	case 7:
		currentBlockSprites = block_L.rotateBlockCC_L(rotation, currentBlockSprites);
		break;
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (currentBlockSprites[i].getPosition().x == 0 || currentBlockSprites[i].getPosition().x == blockSize * 11 || currentBlockSprites[i].getPosition().x == blockSize * 28 || currentBlockSprites[i].getPosition().x == blockSize * 39 || currentBlockSprites[i].getPosition().y == blockSize * 19)
		{
			rotateClockwise(rb, spritesVector);
			break;
		}
		for (int j = 0; j < spritesVector.size() - vectorSize; j++)
		{
			if (currentBlockSprites[i].getPosition().x == spritesVector[j].getPosition().x && currentBlockSprites[i].getPosition().y == spritesVector[j].getPosition().y)
			{
				rotateClockwise(rb, spritesVector);
				break;
			}
		}
	}
}

void Blocks::nextBlock(bool direction)
{
	// Moves the block you have coming next from "next block area" to the playing field and vise versa
	if (direction == true)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			currentBlockSprites[i].move(blockSize * 10, blockSize);
		}
	}
	else
	{
		for (int i = 0; i < vectorSize; i++)
		{
			currentBlockSprites[i].move(-blockSize * 10, -blockSize);
		}
	}
}

void Blocks::seperateBlocks()
{
	// Used in Inverse Tetris to divide the block into two sections when it warps from one side to another
	for (int i = 0; i < currentBlockSprites.size(); i++)
	{
		if (currentBlockSprites[i].getPosition().x < blockSize)
		{
			currentBlockSprites[i].move(blockSize * 10, 0);
		}
		else if (currentBlockSprites[i].getPosition().x > blockSize * 10)
		{
			currentBlockSprites[i].move(-blockSize * 10, 0);
		}
	}
}

int Blocks::clearBlocks(bool cr, int rn, int rc, int loopI)
{
	// Another way to clear blocks when the row is full because the original way doesn't work in Inverse Tetris
	for (int i = 0; i < currentBlockSprites.size(); i++)
	{
		if (cr == true && currentBlockSprites[i].getPosition().y == rn)
		{
			currentBlockSprites[i].move(0, blockSize * 30);
			rc++;
		}
		else if (cr == true && currentBlockSprites[i].getPosition().y < rn)
		{
			currentBlockSprites[i].move(0, blockSize);
		}
		if (cr == false && currentBlockSprites[i].getPosition().y == loopI)
		{
			rc++;
		}
	}
	return rc;
}

std::vector<sf::Sprite>Blocks::getVector()
{
	return currentBlockSprites;
}