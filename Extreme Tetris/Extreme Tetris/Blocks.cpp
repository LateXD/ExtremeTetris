#include "Blocks.h"


Blocks::Blocks()
{
}


Blocks::~Blocks()
{
}

void Blocks::spawnBlock()
{

}

void Blocks::texture(Blocks block)
{
	if (!blockTexture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Error loading block texture" << std::endl;
	}
	// block.setTexture(blockTexture);
}