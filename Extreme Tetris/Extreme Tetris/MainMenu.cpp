#include "MainMenu.h"
#include "StateStart.h"


MainMenu::MainMenu(Game* game)
{
	this->game = game;
}

void MainMenu::draw(const float dt)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		std::cout << "TESTING";
		this->game->window.draw(menu[i]);
	}
}

void MainMenu::Main(float width, float height)
{
	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
	}

	menu[0].setFont(font);
	menu[2].setFont(font);
	menu[3].setFont(font);
	menu[4].setFont(font);

	menu[1].setString("Main Menu");
	menu[1].setColor(sf::Color::Green);
	menu[1].setCharacterSize(50);
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[2].setString("Single Player");
	menu[2].setColor(sf::Color::Red);
	menu[2].setCharacterSize(40);
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[3].setString("Options");
	menu[3].setColor(sf::Color::White);
	menu[3].setCharacterSize(40);
	menu[3].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[4].setString("Quit");
	menu[4].setColor(sf::Color::White);
	menu[4].setCharacterSize(40);
	menu[4].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

}

void MainMenu::update(const float dt)
{

}
void MainMenu::handleInput()
{
	sf::Event event;

	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				this->game->pushState(new StateStart(this->game));
				std::cout << "Mainmenusta -> statestart";
				return;
			}
		}
		default:
			break;
		}
	}
}
MainMenu::~MainMenu()
{
}
