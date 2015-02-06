#ifndef BLOCKS_H
#define BLOCKS_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Blocks
{
public:
	Blocks();
	~Blocks();
	void spawnBlock();
	void setTexture(Blocks block);

private:
	Texture blockTexture;

};

#endif