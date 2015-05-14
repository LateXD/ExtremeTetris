#ifndef BLOCK_L_H
#define BLOCK_L_H

#include "Game.h"

class Block_L
{
public:
	Block_L();
	~Block_L();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockC_L(int rotation, std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockCC_L(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif