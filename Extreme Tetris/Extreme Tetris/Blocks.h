#ifndef BLOCKS_H
#define BLOCKS_H
#include "Game.h"



class Blocks
{
public:
	Blocks();
	~Blocks();
	void spawnBlock();
	void texture(Blocks block);

private:
	sf::Texture blockTexture;

};

#endif