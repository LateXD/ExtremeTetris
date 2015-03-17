#include "Block_S.h"


Block_S::Block_S()
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Can't load texture!";
	}
}


Block_S::~Block_S()
{
}

std::vector<sf::Sprite> Block_S::spawn(int x, int y, std::vector<sf::Sprite> vector)
{
	for (int i = 0; i < vectorSize; i++)
	{
		if (i == 0)
		{
			y++;
		}
		block.setTexture(blockTexture);
		block.setColor(sf::Color(0, 255, 0));
		block.setPosition(blockSize * 4 + x * blockSize, blockSize * 2 + y * blockSize);

		vector.push_back(block);
		if (i == 0)
		{
			x++;
		}
		else if (i == 1)
		{
			y--;
		}
		else if (i == 2)
		{
			x++;
		}
	}
	return vector;
}