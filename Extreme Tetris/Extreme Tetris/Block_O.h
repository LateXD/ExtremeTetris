#ifndef BLOCK_O_H
#define BLOCK_O_H
#include "Blocks.h"

using namespace sf;

class Block_O
{
public:
	Block_O(Sprite block);
	~Block_O();
	void setColor(Sprite block);

private:
	Sprite block_O;

};

#endif