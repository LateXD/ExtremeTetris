#ifndef BLOCK_O_H
#define BLOCK_O_H

#include "Game.h"

class Block_O
{
public:
	Block_O();
	~Block_O();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	void rotateBlock_O(int rotation);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif