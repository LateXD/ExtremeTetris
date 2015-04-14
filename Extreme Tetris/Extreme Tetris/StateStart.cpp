#include "StateStart.h"

StateStart::StateStart(Game* game) 
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
	frame.setTexture(frameTexture);
	frame.setColor(sf::Color(100, 255, 100));
	pointsFrame.setTexture(pointsFrameTexture);
	pointsFrame.setColor(sf::Color(100, 255, 100));
	pointsFrame.setPosition(blockSize * 12, 0);

	randomBlock2 = randomBlock;
	blockVector.push_back(new Blocks(randomBlock));
	randomBlock = rand() % 7 + 1;
	block = new Blocks(randomBlock);
	block->nextBlock(direction);
	direction = false;

	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
		std::cout << "" << std::endl;
	}

	pointsText.setFont(font);
	pointsText.setColor(sf::Color::Green);
	pointsText.setCharacterSize(20);
	pointsText.setPosition(sf::Vector2f(blockSize * 18, blockSize * 8.75));
	ss << points;
	pointsText.setString(ss.str());
}

void StateStart::draw(const float dt)
{
	// Jos halutaan käyttää toista näkymää (View), tulee
	// vanha ensiksi ottaa talteen, jotta siihen voidaan palata.

	//this->game->window.setView(this->view);
	this->game->window.clear(sf::Color::Black);
	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = block->getVector();
		for (int i = 0; i < 4; i++)
		{
			game->window.draw(spriteVector[i]);
		}
	}
	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
		for (int i = 0; i < 4; i++)
		{
			game->window.draw(spriteVector[i]);
		}
	}
	game->window.draw(frame);
	game->window.draw(pointsFrame);
	game->window.draw(pointsText);
}


void StateStart::handleInput()
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
				//TODO:: IF YOU WANT TO RESIZE THE WINDOW

			/*case sf::Event::Resized:
			{

			}*/

			case sf::Event::KeyPressed:
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					this->game->pushState(new MainMenu(this->game));
					std::cout << "Back to main menu\n";
					return;
				}

				else if (event.key.code == sf::Keyboard::Left)
				{
					for (int i = 0; i < vectorSize; i++)
					{
						if (spriteVector[i].getPosition().x - 20 > 0)
						{
							positionCounter++;
						}
					}
					if (positionCounter == vectorSize)
					{
						blockVector[locationNumber]->moveLeft();
					}
					positionCounter = 0;
				}

				else if (event.key.code == sf::Keyboard::Right) 
				{
					for (int i = 0; i < vectorSize; i++)
					{
						if (spriteVector[i].getPosition().x + 20 < 11 * blockSize)
						{
							positionCounter++;
						}
					}
					if (positionCounter == vectorSize)
					{
						blockVector[locationNumber]->moveRight();
					}
					positionCounter = 0;
				}

				else if (event.key.code == sf::Keyboard::Down && clock.getElapsedTime().asMicroseconds() < 500000)
				{
					for (int i = 0; i < vectorSize; i++)
					{
						if (spriteVector[i].getPosition().y + 20 < 19 * blockSize)
						{
							positionCounter++;
						}
					}
					if (positionCounter == vectorSize)
					{
						blockVector[locationNumber]->moveDown();
						pointsCounter++;
					}
					positionCounter = 0;
				}

				else if (event.key.code == sf::Keyboard::M)
				{
					blockVector[locationNumber]->rotateClockwise(randomBlock2);
				}

				else if (event.key.code == sf::Keyboard::N)
				{
					blockVector[locationNumber]->rotateCounterClockwise(randomBlock2);
				}

			default:
				break;
			}

			case sf::Event::KeyReleased:
			{
				if (event.key.code == sf::Keyboard::Down)
				{
					pointsCounter = 0;
				}
			}

		}
	}
}

void StateStart::update(const float dt)
{
	for (int i = 0; i < vectorSize; i++)
	{
		if (spriteVector.size() != 0 && spriteVector[i].getPosition().y + 20 > 18 * blockSize)
		{
			clock.restart();
			randomBlock2 = randomBlock;
			blockVector.push_back(block);
			block->nextBlock(direction);
			direction = true;
			randomBlock = rand() % 7 + 1;
			block = new Blocks(randomBlock);
			block->nextBlock(direction);
			direction = false;
			points += pointsCounter;
			pointsCounter = 0;
			locationNumber++;
			ss.clear();
			ss.str("");
			if (points >= pointsMover)
			{
				pointsText.move(-10, 0);
				pointsMover = pointsMover * 10;
			}
			ss << points;
			pointsText.setString(ss.str());
			break;
		}
	}
	if (clock.getElapsedTime().asMicroseconds() >= 500000)
	{
		blockVector[locationNumber]->moveDown();
		clock.restart();
	}
}

StateStart::~StateStart()
{
}