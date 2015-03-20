#include "Block_T.h"


Block_T::Block_T()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_T::~Block_T()
{
}

std::vector<sf::Sprite> Block_T::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		block.setTexture(blockTexture);
		block.setColor(sf::Color(163, 73, 164));
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
			x--;
			y++;
		}
	}
	return vector;
}

std::vector<sf::Sprite> Block_T::rotateBlock_T(int rotation, std::vector<sf::Sprite> vector)
{

	return vector;
}