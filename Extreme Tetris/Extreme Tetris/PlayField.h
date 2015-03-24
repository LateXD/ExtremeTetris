#ifndef PLAYFIELD_H
#define PLAYFIELD_H

#include "Game.h"

class PlayField
{
public:
	PlayField();
	~PlayField();
	void setField(int tile);
	void printField();

private:
	int xSize = 12, ySize = 20, counter = 0;
	std::vector<int>fieldVector;
};

#endif