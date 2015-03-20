#include "Block_J.h"


Block_J::Block_J()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_J::~Block_J()
{
}

std::vector<sf::Sprite> Block_J::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(0, 0, 255));
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
			y++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_J::rotateBlockC_J(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[2].move(blockSize, blockSize);
	}
	else if (rotation == 1)
	{
		vector[0].move(0, -blockSize);
		vector[2].move(-blockSize, -blockSize * 2);
	}
	else if (rotation == 2)
	{
		vector[0].move(-blockSize, blockSize * 2);
		vector[2].move(0, blockSize);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, -blockSize);
	}
	return vector;
}

std::vector<sf::Sprite> Block_J::rotateBlockCC_J(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[0].move(-blockSize, blockSize);
	}
	else if (rotation == 1)
	{
		vector[2].move(-blockSize, -blockSize);
	}
	else if (rotation == 2)
	{
		vector[0].move(0, blockSize);
		vector[2].move(blockSize, blockSize * 2);
	}
	else if (rotation == 3)
	{
		vector[0].move(blockSize, -blockSize * 2);
		vector[2].move(0, -blockSize);
	}
	return vector;
}