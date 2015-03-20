#include "Block_Z.h"


Block_Z::Block_Z()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_Z::~Block_Z()
{
}

std::vector<sf::Sprite> Block_Z::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(255, 0, 0));
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
			x++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_Z::rotateBlock_Z(int rotation, std::vector<sf::Sprite> vector)
{
	if (rotation == 1)
	{
	vector[2].move(0, -blockSize * 2);
	vector[3].move(-blockSize * 2, 0);
	}
	else if (rotation == 0)
	{
	vector[2].move(0, blockSize * 2);
	vector[3].move(blockSize * 2, 0);
	}
	return vector;
}