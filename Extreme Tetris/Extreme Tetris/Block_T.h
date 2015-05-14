#ifndef BLOCK_T_H
#define BLOCK_T_H

#include "Game.h"

class Block_T
{
public:
	Block_T();
	~Block_T();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockC_T(int rotation, std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockCC_T(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif