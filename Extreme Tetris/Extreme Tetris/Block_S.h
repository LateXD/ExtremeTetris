#ifndef BLOCK_S_H
#define BLOCK_S_H
#include "Game.h"


class Block_S
{
public:
	Block_S();
	~Block_S();
	std::vector<sf::Sprite> spawn(int x, int y, std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlock_S(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif