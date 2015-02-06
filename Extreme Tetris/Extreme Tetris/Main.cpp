#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Window/Event.hpp>


using namespace sf;

int main()
{
	sf::Texture texture;
	sf::Sprite sprite;
	if (!texture.loadFromFile("C:\\Users\ttv14slaurih\Documents\GitHub\ExtremeTetris\Graphics\Block.png"))
	{
		// error...
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);

	RenderWindow window(VideoMode(200u, 200u), "SFML Demo");
	Event event;
	window.draw(sprite);

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
	}
	return 0;
}