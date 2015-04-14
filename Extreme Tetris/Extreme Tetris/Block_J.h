#ifndef BLOCK_J_H
#define BLOCK_J_H
#include "Game.h"


class Block_J
{
public:
	Block_J();
	~Block_J();
	std::vector<sf::Sprite> spawn(std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockC_J(int rotation, std::vector<sf::Sprite> vector);
	std::vector<sf::Sprite> rotateBlockCC_J(int rotation, std::vector<sf::Sprite> vector);

private:
	int blockSize = 20, vectorSize = 4, xPos = 0, yPos = 0;
	sf::Sprite block;
	sf::Texture blockTexture;
};

#endif