#include "Block_J.h"


Block_J::Block_J()
{
}


Block_J::~Block_J()
{
}

std::vector<sf::Sprite> Block_J::spawn(std::vector<sf::Sprite> vector)
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(0, 0, 255));
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
			yPos++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_J::rotateBlockC_J(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[0].move(-blockSize, -blockSize);
		vector[2].move(blockSize, blockSize);
		vector[3].move(0, blockSize * 2);
	}
	else if (rotation == 1)
	{
		vector[0].move(blockSize, blockSize);
		vector[2].move(-blockSize, -blockSize);
		vector[3].move(-blockSize * 2, 0);
	}
	else if (rotation == 2)
	{
		vector[0].move(-blockSize, -blockSize);
		vector[2].move(blockSize, blockSize);
		vector[3].move(0, -blockSize * 2);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, blockSize);
		vector[2].move(-blockSize, -blockSize);
		vector[3].move(blockSize * 2, 0);
	}
	return vector;
}

std::vector<sf::Sprite> Block_J::rotateBlockCC_J(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[0].move(-blockSize, -blockSize);
		vector[2].move(blockSize, blockSize);
		vector[3].move(blockSize * 2, 0);
	}
	else if (rotation == 1)
	{
		vector[0].move(blockSize, blockSize);
		vector[2].move(-blockSize, -blockSize);
		vector[3].move(0, blockSize * 2);
	}
	else if (rotation == 2)
	{
		vector[0].move(-blockSize, -blockSize);
		vector[2].move(blockSize, blockSize);
		vector[3].move(-blockSize * 2, 0);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, blockSize);
		vector[2].move(-blockSize, -blockSize);
		vector[3].move(0, -blockSize * 2);
	}
	return vector;
}