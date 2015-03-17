#ifndef BLOCK_J_H
#define BLOCK_J_H
#include "Game.h"


class Block_J
{
public:
	Block_J();
	~Block_J();
	std::vector<sf::Sprite> spawn(int x, int y, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif