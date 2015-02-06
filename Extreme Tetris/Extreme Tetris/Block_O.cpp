#include "Block_O.h"


Block_O::Block_O(Sprite block)
{
	block = block_O;
}


Block_O::~Block_O()
{
}

void Block_O::setColor(Sprite block)
{
	block.setColor(sf::Color(255, 255, 0)); // yellow
}
