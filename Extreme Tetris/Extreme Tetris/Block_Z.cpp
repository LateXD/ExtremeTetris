#include "Block_Z.h"


Block_Z::Block_Z()
{
}


Block_Z::~Block_Z()
{
}

std::vector<sf::Sprite> Block_Z::spawn(std::vector<sf::Sprite> vector)
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(255, 0, 0));
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
			xPos++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_Z::rotateBlock_Z(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 0)
	{
		vector[2].move(0, blockSize * 2);
		vector[3].move(blockSize * 2, 0);
	}
	else if (rotation == 1)
	{
	vector[2].move(0, -blockSize * 2);
	vector[3].move(-blockSize * 2, 0);
	}
	return vector;
}