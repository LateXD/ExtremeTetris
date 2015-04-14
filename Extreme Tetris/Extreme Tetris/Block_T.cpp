#include "Block_T.h"


Block_T::Block_T()
{
}


Block_T::~Block_T()
{
}

std::vector<sf::Sprite> Block_T::spawn(std::vector<sf::Sprite> vector)
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(163, 73, 164));
		block.setPosition(blockSize * 4 + xPos * blockSize, blockSize * 2 + yPos * blockSize);
		vector.push_back(block);
		if (i == 0)
		{
			xPos++;
		}
		else if (i == 1)
		{
			xPos++;
		}
		else if (i == 2)
		{
			xPos--;
			yPos++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_T::rotateBlockC_T(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[0].move(-blockSize, -blockSize);
		vector[2].move(blockSize, blockSize);
		vector[3].move(-blockSize, blockSize);
	}
	else if (rotation == 1)
	{
		vector[2].move(-blockSize, -blockSize);
	}
	else if (rotation == 2)
	{
		vector[3].move(blockSize, -blockSize);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, blockSize);
	}
	return vector;
}

std::vector<sf::Sprite> Block_T::rotateBlockCC_T(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[2].move(blockSize, blockSize);
	}
	else if (rotation == 1)
	{
		vector[3].move(-blockSize, blockSize);
	}
	else if (rotation == 2)
	{
		vector[0].move(-blockSize, -blockSize);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, blockSize);
		vector[2].move(-blockSize, -blockSize);
		vector[3].move(blockSize, -blockSize);
	}
	return vector;
}