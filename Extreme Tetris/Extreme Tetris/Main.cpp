#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>


using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600u, 400u), "Extreme Tetris");
	
	Texture texture;
	Sprite sprite;
	Clock clock;
	unsigned short frames = 0;
	window.setFramerateLimit(30);
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
		if (clock.getElapsedTime() .asMicroseconds() >= 500000)
		{
			system("cls");
			std::cout << "FPS: " << frames * 2 << "\n";
			frames = 0;
			clock.restart();
		}
		else
		{
			frames++;
		}
	}
	return 0;
}