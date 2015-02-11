#ifndef BLOCK_O_H
#define BLOCK_O_H
#include "Blocks.h"



class Block_O
{
public:
	Block_O(sf::Sprite block);
	~Block_O();
	void setColor(sf::Sprite block);

private:
	sf::Sprite block_O;

};

#endif