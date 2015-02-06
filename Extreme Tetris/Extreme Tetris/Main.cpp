#include "Blocks.h"

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(600u, 400u), "Extreme Tetris");
	
	Texture texture;
	Sprite sprite, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7;
	Clock clock;
	unsigned short frames = 0;
	window.setFramerateLimit(30);
	if (!texture.loadFromFile("..\\Graphics\\Block2.png"))
	{
		std::cout << "Error loading block texture" << std::endl;
	}

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

		/*
		sprite.setColor(sf::Color(255, 255, 0)); // yellow
		sprite2.setColor(sf::Color(0, 255, 255)); // teal
		sprite3.setColor(sf::Color(255, 0, 255)); // purple
		sprite4.setColor(sf::Color(0, 0, 255)); // blue
		sprite5.setColor(sf::Color(255, 0, 0)); // red
		sprite6.setColor(sf::Color(0, 255, 0)); // green
		sprite7.setColor(sf::Color(255, 130, 40)); // orange
		*/

		sprite.setScale(sf::Vector2f(5.f, 5.f));


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