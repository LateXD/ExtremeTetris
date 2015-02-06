#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>


using namespace sf;

int main()
{
	RenderWindow window(VideoMode(400u, 400u), "SFML Demo");
	
	
	Texture texture;
	Sprite sprite;

	if (!texture.loadFromFile("..\\Graphics\\Block.png"))
	{
		std::cout << "Error loading block texture" << std::endl;
	}
	

	texture.setSmooth(true);
	sprite.setTexture(texture);


	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(sprite);
		window.display();
	}
	return 0;
}