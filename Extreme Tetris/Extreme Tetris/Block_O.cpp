#include "Block_O.h"


Block_O::Block_O()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_O::~Block_O()
{
}

std::vector<sf::Sprite> Block_O::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(255, 255, 0));
		block.setPosition(blockSize * 4 + x * blockSize, blockSize * 2 + y * blockSize);
		vector.push_back(block);
		if (i == 0)
		{
			x++;
		}
		else if (i == 1)
		{
			y++;
		}
		else if (i == 2)
		{
			x--;
		}
	}
	return vector;
}

void Block_O::rotateBlock_O(int rotation)
{
	/*
	if (rotation < 0)
	{
		rotation = 1;
	}
	else if (rotation > 1)
	{
		rotation = 0;
	}

	if (rotation == 0)
	{
		block_O[2].move(0, -blockSize * 2);
		block_O[3].move(-blockSize * 2, 0);
	}
	else if (rotation == 1)
	{
		block_O[2].move(0, blockSize * 2);
		block_O[3].move(blockSize * 2, 0);
	}
	*/
}