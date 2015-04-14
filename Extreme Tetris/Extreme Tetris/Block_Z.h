#ifndef BLOCK_Z_H
#define BLOCK_Z_H
#include "Game.h"


class Block_Z
{
public:
	Block_Z();
	~Block_Z();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlock_Z(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif