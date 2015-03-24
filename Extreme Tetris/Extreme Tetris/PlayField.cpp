#include "PlayField.h"


PlayField::PlayField()
{
	for (int i = 0; i < xSize * ySize; i++)
	{
		if (i < xSize || i == xSize * counter || i == xSize * counter - 1 || i >= xSize * ySize - xSize)
		{
			fieldVector.push_back(2);
			if (i == xSize * counter)
			{
				counter++;
			}
		}
		else
		{
			fieldVector.push_back(0);
		}
	}
}


PlayField::~PlayField()
{
}

void PlayField::setField(int tile)
{
	fieldVector[tile] = 1;
}

void PlayField::printField()
{
	counter = 1;
	for (int i = 0; i < xSize * ySize; i++)
	{
		std::cout << fieldVector[i];
		if (i == xSize * counter - 1)
		{
			std::cout << std::endl;
			counter++;
		}
	}
}