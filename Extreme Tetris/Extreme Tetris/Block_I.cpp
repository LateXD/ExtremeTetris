#include "Block_I.h"


Block_I::Block_I()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_I::~Block_I()
{
}

std::vector<sf::Sprite> Block_I::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(26, 186, 255));
		block.setPosition(blockSize * 4 + x * blockSize, blockSize * 2 + y * blockSize);
		vector.push_back(block);
		if (i == 0)
		{
			x++;
		}
		else if (i == 1)
		{
			x++;
		}
		else if (i == 2)
		{
			x++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_I::rotateBlock_I(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[0].move(-blockSize, blockSize);
		vector[2].move(blockSize, -blockSize);
		vector[3].move(blockSize * 2, blockSize * 2);
	}
	else if (rotation == 1)
	{
		vector[0].move(blockSize, -blockSize);
		vector[2].move(-blockSize, blockSize);
		vector[3].move(-blockSize * 2, -blockSize * 2);
	}
	return vector;
}