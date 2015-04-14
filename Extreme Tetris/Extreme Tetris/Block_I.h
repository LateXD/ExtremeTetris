#ifndef BLOCK_I_H
#define BLOCK_I_H
#include "Game.h"


class Block_I
{
public:
	Block_I();
	~Block_I();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlock_I(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif