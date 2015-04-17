#include "MultiplayerState.h"


MultiplayerState::MultiplayerState(Game* game)
{
	this->game = game;
	
	if (!frameTexture.loadFromFile("..\\Graphics\\Frame.png"))
	{
		std::cout << "Can't load texture!";
	}

	if (!pointsFrameTexture.loadFromFile("..\\Graphics\\Frame2.png"))
	{
		std::cout << "Can't load texture!";
	}
	
	

	// Frame 1
	frame.setTexture(frameTexture);
	frame.setColor(sf::Color(100, 255, 100));

	//Frame 2
	frame2.setTexture(frameTexture);
	frame2.setColor(sf::Color(255, 100, 100));
	frame2.setPosition(sf::Vector2f(blockSize * 28, 0));

	// PointsFrame 1
	pointsFrame.setTexture(pointsFrameTexture);
	pointsFrame.setColor(sf::Color(100, 255, 100));
	pointsFrame.setPosition(blockSize * 12, 0);
	pointsText.setFont(font);
	pointsText.setColor(sf::Color::Green);
	pointsText.setCharacterSize(20);
	pointsText.setPosition(sf::Vector2f(blockSize * 18, blockSize * 8.75));

	// PointsFrame 2
	pointsFrame2.setTexture(pointsFrameTexture);
	pointsFrame2.setColor(sf::Color(255, 100, 100));
	pointsFrame2.setPosition(blockSize * 20, 0);
	
}

void MultiplayerState::draw(const float dt)
{
	this->game->window.clear(sf::Color::Black);

	// Draw frame 1, next block and points
	game->window.draw(frame);
	game->window.draw(pointsFrame);
	game->window.draw(pointsText);

	game->window.draw(frame2);
	game->window.draw(pointsFrame2);

	
}

void MultiplayerState::handleInput()
{
	sf::Event event;
	while (this->game->window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
		{
			game->window.close();
			break;
		}
		case sf::Event::KeyPressed:
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				this->game->pushState(new MainMenu(this->game));
				std::cout << "Back to main menu\n";
				return;
			}
		}
		default:
			break;
		}

	}
}

void MultiplayerState::update(const float dt)
{

}


MultiplayerState::~MultiplayerState()
{
}
