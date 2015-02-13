#include "Game.h"
#include "MainMenu.h"

int main()
{
	Game game;
	game.pushState(new MainMenu(&game));
	game.gameLoop();							//gameLoop() metodissa pyörii itse peli
												//ja toimii ns. main.cpp:nä

	return 0;
}



/*VANHA MAIN ALHAALLA*/

///////////////////////////////////////////////////////////////////////////////////////////

//#include "Blocks.h"

//using namespace sf;

//int main()
//{
//	RenderWindow window(VideoMode(600u, 400u), "Extreme Tetris");
//
//	Texture texture;
//	Sprite sprite, sprite2, sprite3, sprite4, sprite5, sprite6, sprite7;
//	Clock clock;
//	unsigned short frames = 0;
//	window.setFramerateLimit(30);
//	if (!texture.loadFromFile("..\\Graphics\\Block.png"))
//	{
//		std::cout << "Error loading block texture" << std::endl;
//	}
//
//	sprite.setTexture(texture);
//	sprite.setOrigin(sf::Vector2f(8, 8));
//	sprite.setPosition(8, 8);
//
//	while (window.isOpen())
//	{
//		Event event;
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::KeyPressed)
//			{
//				if (event.key.code == sf::Keyboard::Z)
//				{
//					sprite.rotate(-90);
//				}
//				else if (event.key.code == sf::Keyboard::X)
//				{
//					sprite.rotate(90);
//				}
//				else if (event.key.code == sf::Keyboard::Down)
//				{
//					sprite.move(0, 16);
//				}
//				else if (event.key.code == sf::Keyboard::Left)
//				{
//					sprite.move(-16, 0);
//				}
//				else if (event.key.code == sf::Keyboard::Right)
//				{
//					sprite.move(16, 0);
//				}
//			}
//			if (event.type == Event::Closed)
//			{
//				window.close();
//			}
//		}
//
//		sprite.setColor(sf::Color(255, 255, 0)); // yellow
//		/*
//		sprite2.setColor(sf::Color(0, 255, 255)); // teal
//		sprite3.setColor(sf::Color(255, 0, 255)); // purple
//		sprite4.setColor(sf::Color(0, 0, 255)); // blue
//		sprite5.setColor(sf::Color(255, 0, 0)); // red
//		sprite6.setColor(sf::Color(0, 255, 0)); // green
//		sprite7.setColor(sf::Color(255, 130, 40)); // orange
//		*/
//
//		
//		window.clear();
//		window.draw(sprite);
//		window.display();
//	
		//if (clock.getElapsedTime() .asMicroseconds() >= 500000)
		//{
		//	system("cls");
		//	std::cout << "FPS: " << frames * 2 << "\n";
		//	frames = 0;
		//	clock.restart();
		//}
		//else
		//{
		//	frames++;
		//}
//	}
//	return 0;
//}