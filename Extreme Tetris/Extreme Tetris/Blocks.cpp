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
	std::cout << "Block removed.";
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

void Blocks::rotateClockwise(int rb, std::vector<sf::Sprite> spritesVector)
{
	// Rotation decides how the block should be rotated, for example if rb (randomBlock) = 4 (I block) and rotation = 1 it adds one to rotation which makes it 2 but as I block has only 2 poses it will go back to 0
	// Then it checks which block type you have at the moment, rotate it and if there's something wrong (it's inside a wall or another block), it rotates it back
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
	else if (rb == 4)
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

	for (int i = 0; i < vectorSize; i++)
	{
		if (blockVector[i].getPosition().x <= 0 || blockVector[i].getPosition().x >= blockSize * 11 || blockVector[i].getPosition().y >= blockSize * 19)
		{
			rotateCounterClockwise(rb, spritesVector);
			break;
		}
		for (int j = 0; j < spritesVector.size() - vectorSize; j++)
		{
			if (blockVector[i].getPosition().x == spritesVector[j].getPosition().x && blockVector[i].getPosition().y == spritesVector[j].getPosition().y)
			{
				rotateCounterClockwise(rb, spritesVector);
				break;
			}
		}
	}
}

void Blocks::rotateCounterClockwise(int rb, std::vector<sf::Sprite> spritesVector)
{
	// Pretty much the same as before but rotation happens counterclockwise
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

	for (int i = 0; i < vectorSize; i++)
	{
		if (blockVector[i].getPosition().x <= 0 || blockVector[i].getPosition().x >= blockSize * 11 || blockVector[i].getPosition().y >= blockSize * 19)
		{
			rotateClockwise(rb, spritesVector);
			break;
		}
		for (int j = 0; j < spritesVector.size() - vectorSize; j++)
		{
			if (blockVector[i].getPosition().x == spritesVector[j].getPosition().x && blockVector[i].getPosition().y == spritesVector[j].getPosition().y)
			{
				rotateClockwise(rb, spritesVector);
				break;
			}
		}
	}
}

void Blocks::nextBlock(bool direction)
{
	// Moves the block you have coming next from its place to the playing field and vise versa
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