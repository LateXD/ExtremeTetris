#include "InputState.h"
#include "OptionsState.h"


InputState::InputState(Game* game)
{
	this->game = game;
}

void InputState::draw(const float dt)
{
	for (int i = 0; i < INPUT_ITEMS; i++)
	{
		game->window.draw(this->input[i]);
	}
}

void InputState::onInitialize()
{
	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
		std::cout << "" << std::endl;
	}

	float width = game->getWindowWidth();
	float height = game->getWindowHeight();

	input[0].setFont(font);
	input[1].setFont(font);
	input[2].setFont(font);
	input[3].setFont(font);
	input[4].setFont(font);
	input[5].setFont(font);

	input[0].setString("Controls");
	input[0].setColor(sf::Color::Magenta);
	input[0].setCharacterSize(40);
	input[0].setPosition(sf::Vector2f(width / 4, height / (OPTIONS_ITEMS + 6) * 1));

	input[1].setString("Move left:");
	input[1].setColor(sf::Color::Red);
	input[1].setCharacterSize(30);
	input[1].setPosition(sf::Vector2f(width / 5, height / (OPTIONS_ITEMS + 5) * 2));

	input[2].setString("Move right:");
	input[2].setColor(sf::Color::White);
	input[2].setCharacterSize(30);
	input[2].setPosition(sf::Vector2f(width / 5, height / (OPTIONS_ITEMS + 5) * 3));

	input[3].setString("Move down:");
	input[3].setColor(sf::Color::White);
	input[3].setCharacterSize(30);
	input[3].setPosition(sf::Vector2f(width / 5, height / (OPTIONS_ITEMS + 5) * 4));

	input[4].setString("Rotate counterclockwise:");
	input[4].setColor(sf::Color::White);
	input[4].setCharacterSize(30);
	input[4].setPosition(sf::Vector2f(width / 5, height / (OPTIONS_ITEMS + 5) * 5));

	input[5].setString("Rotate clockwise:");
	input[5].setColor(sf::Color::White);
	input[5].setCharacterSize(30);
	input[5].setPosition(sf::Vector2f(width / 5, height / (OPTIONS_ITEMS + 5) * 6));

	
}

void InputState::MoveUp()
{
	if (selectedItemIndex > 1)
	{
		input[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex--;
		input[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void InputState::MoveDown()
{
	if (selectedItemIndex < INPUT_ITEMS - 1)
	{
		input[selectedItemIndex].setColor(sf::Color::White);
		selectedItemIndex++;
		input[selectedItemIndex].setColor(sf::Color::Red);
	}

}

int InputState::GetPressedItem()
{
	return selectedItemIndex;
}

void InputState::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				this->game->pushState(new OptionsState(this->game));
				return;
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
					break;
				case 2:
					break;
				case 3:
					break;
				case 4:
					break;
				case 5:
					break;
				default:
					break;
				}
			default:
				break;
			}
		}
		default:
			break;
		}
	}
}
void InputState::update(const float dt)
{

}

InputState::~InputState()
{
}
