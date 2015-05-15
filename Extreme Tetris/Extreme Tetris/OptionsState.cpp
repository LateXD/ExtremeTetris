#include "OptionsState.h"
#include "MainMenu.h"

#include "InputState.h"

OptionsState::OptionsState(Game* game)
{
	this->game = game;
}

void OptionsState::draw(const float dt)
{
	for (int i = 0; i < OPTIONS_ITEMS; i++)
	{
		game->window.draw(this->options[i]);
	}
}

void OptionsState::onInitialize()
{
	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
		std::cout << "" << std::endl;
	}
	
	float width = game->getWindowWidth();
	float height = game->getWindowHeight();

	options[0].setFont(font);
	options[1].setFont(font);
	options[2].setFont(font);

	options[0].setString("Options");
	options[0].setColor(sf::Color::Yellow);
	options[0].setCharacterSize(50);
	options[0].setPosition(sf::Vector2f(width / 6, height / (OPTIONS_ITEMS + 2) * 1));

	options[1].setString("Controls");
	options[1].setColor(sf::Color::Red);
	options[1].setCharacterSize(40);
	options[1].setPosition(sf::Vector2f(width / 6, height / (OPTIONS_ITEMS + 1) * 2));

	options[2].setString("Volume");
	options[2].setColor(sf::Color::White);
	options[2].setCharacterSize(40);
	options[2].setPosition(sf::Vector2f(width / 6, height / (OPTIONS_ITEMS + 1) * 3));

}

void OptionsState::MoveUp()
{
	if (selectedItemIndex > 1)
	{
		options[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		options[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void OptionsState::MoveDown()
{
	if (selectedItemIndex < OPTIONS_ITEMS - 1)
	{
		options[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		options[selectedItemIndex].setColor(sf::Color::Red);
	}
}

int OptionsState::GetPressedItem()
{
	return selectedItemIndex;
}

void OptionsState::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		this->game->pushState(new MainMenu(this->game));
		return;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		MoveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		MoveDown();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (GetPressedItem())
		{
		case 1:
			this->game->pushState(new InputState(this->game));
			std::cout << "Inputs" << std::endl;
			break;
		case 2:
			std::cout << "Volume" << std::endl;
			break;
		default:
			break;
		}
	}
}

void OptionsState::update(const float dt)
{

}

OptionsState::~OptionsState()
{
}
