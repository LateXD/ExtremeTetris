#include "MainMenu.h"
#include "StateStart.h"
#include "OptionsState.h"
#include "MultiplayerState.h"


MainMenu::MainMenu(Game* game)
{
	this->game = game;
}

void MainMenu::draw(const float dt)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		game->window.draw(this->menu[i]);
	}
}

void MainMenu::onInitialize()
{
	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
		std::cout << "" << std::endl;
	}

	float width = game->getWindowWidth();
	float height = game->getWindowHeight();

	menu[0].setFont(font);
	menu[1].setFont(font);
	menu[2].setFont(font);
	menu[3].setFont(font);
	menu[4].setFont(font);

	menu[0].setString("Main Menu");
	menu[0].setColor(sf::Color::Green);
	menu[0].setCharacterSize(50);
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 2) * 1));

	menu[1].setString("Single Player");
	menu[1].setColor(sf::Color::Red);
	menu[1].setCharacterSize(40);
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setString("Multiplayer");
	menu[2].setColor(sf::Color::White);
	menu[2].setCharacterSize(40);
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	menu[3].setString("Options");
	menu[3].setColor(sf::Color::White);
	menu[3].setCharacterSize(40);
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	menu[4].setString("Quit");
	menu[4].setColor(sf::Color::White);
	menu[4].setCharacterSize(40);
	menu[4].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEMS + 1) * 5));

}

/*void MainMenu::Main(float width, float height)
{
}*/

void MainMenu::MoveUp()
{
	if (selectedItemIndex > 1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void MainMenu::MoveDown()
{
	if (selectedItemIndex < MAX_NUMBER_OF_ITEMS - 1)
	{
		menu[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int MainMenu::GetPressedItem()
{
	return selectedItemIndex;
}

void MainMenu::update(const float dt)
{

}
void MainMenu::handleInput()
{
	sf::Event event;
	system("cls");
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				MoveUp();
				break;

			case sf::Keyboard::Down:
				MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (GetPressedItem())
				{

				case 1:
					this->game->pushState(new StateStart(this->game));
					std::cout << "Single player" << std::endl;
					return;
				case 2:
					this->game->pushState(new MultiplayerState(this->game));
					std::cout << "Multiplayer" << std::endl;
					return;
				case 3:
					this->game->pushState(new OptionsState(this->game));
					std::cout << "Options menu" << std::endl;
					break;
				case 4:
					std::cout << "Quit game" << std::endl;
					this->game->window.close();
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
		}
	}
}

MainMenu::~MainMenu()
{
}
