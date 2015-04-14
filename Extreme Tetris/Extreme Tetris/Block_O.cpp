#include "Block_O.h"

Block_O::Block_O()
{
}


Block_O::~Block_O()
{
}

std::vector<sf::Sprite> Block_O::spawn(std::vector<sf::Sprite> vector)
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(255, 255, 0));
		block.setPosition(blockSize * 4 + xPos * blockSize, blockSize * 2 + yPos * blockSize);
		vector.push_back(block);
		if (i == 0)
		{
			xPos++;
		}
		else if (i == 1)
		{
			yPos++;
		}
		else if (i == 2)
		{
			xPos--;
		}
	}
	return vector;
}

void Block_O::rotateBlock_O(int rotation)
{
}