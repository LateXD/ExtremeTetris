#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

using namespace sf;

int main()
{
	RenderWindow window(VideoMode(200u, 200u), "SFML Demo");
	Event event;

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