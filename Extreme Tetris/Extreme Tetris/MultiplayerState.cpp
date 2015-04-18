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

	if (!font.loadFromFile("..\\Graphics\\8bitOperatorPlus8-Regular.ttf"))
	{
		//error
		std::cout << "" << std::endl;
	}
	
	

	// Frame 1
	frame.setTexture(frameTexture);
	frame.setColor(sf::Color(100, 255, 100));

	// PointsFrame 1
	pointsFrame.setTexture(pointsFrameTexture);
	pointsFrame.setColor(sf::Color(100, 255, 100));
	pointsFrame.setPosition(blockSize * 12, 0);
	pointsText.setFont(font);
	pointsText.setColor(sf::Color::Green);
	pointsText.setCharacterSize(20);
	pointsText.setPosition(sf::Vector2f(blockSize * 18, blockSize * 8.75));
	ss << points;
	pointsText.setString(ss.str());

	// Player 1 blocks
	randomBlock2 = randomBlock;
	blockVector.push_back(new Blocks(randomBlock));
	randomBlock = rand() % 7 + 1;
	block = new Blocks(randomBlock);
	block->nextBlock(direction);
	direction = false;

	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
	}

	// Frame 2
	frame2.setTexture(frameTexture);
	frame2.setColor(sf::Color(255, 100, 100));
	frame2.setPosition(sf::Vector2f(blockSize * 28, 0));

	// PointsFrame 2
	pointsFrame2.setTexture(pointsFrameTexture);
	pointsFrame2.setColor(sf::Color(255, 100, 100));
	pointsFrame2.setPosition(blockSize * 20, 0);
	pointsText2.setFont(font);
	pointsText2.setColor(sf::Color::Red);
	pointsText2.setCharacterSize(20);
	pointsText2.setPosition(sf::Vector2f(blockSize * 26, blockSize * 8.75));
	pointsText2.setString(ss.str());

	// Player 2 blocks
	randomBlock2 = randomBlock;
	blockVector2.push_back(new Blocks(randomBlock));
	randomBlock = rand() % 7 + 1;
	block = new Blocks(randomBlock);
	block->nextBlock(direction);
	direction = false;

	for (int i = 0; i < blockVector2.size(); i++)
	{
		spriteVector2 = blockVector2[i]->getVector();
	}
	
}

void MultiplayerState::draw(const float dt)
{
	this->game->window.clear(sf::Color::White);

	// Draw frame 1, block and points
	game->window.draw(frame);
	game->window.draw(pointsFrame);
	game->window.draw(pointsText);


	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = block->getVector();
		for (int j = 0; j < 4; j++)
		{
			game->window.draw(spriteVector[j]);
		}
	}

	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
	}

	for (int i = 0; i < allSprites.size(); i++)
	{
		game->window.draw(allSprites[i]);
	}


	game->window.draw(frame2);
	game->window.draw(pointsFrame2);
	game->window.draw(pointsText2);

	for (int i = 0; i < blockVector2.size(); i++)
	{
		spriteVector2 = block->getVector();
		for (int j = 0; j < 4; j++)
		{
			game->window.draw(spriteVector2[j]);
		}
	}

	for (int i = 0; i < blockVector2.size(); i++)
	{
		spriteVector2 = blockVector2[i]->getVector();
	}

	for (int i = 0; i < allSprites.size(); i++)
	{
		game->window.draw(allSprites[i]);
	}

	
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
					for (int i = 0; i < vectorSize; i++)
					{
						for (int j = 0; j < allSprites.size() - vectorSize; j++)
						{
							if (spriteVector[i].getPosition().x - blockSize == allSprites[j].getPosition().x && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
							{
								collision = true;
							}
						}
					}
					if (collision == false)
					{
						blockVector[locationNumber]->moveLeft();
					}
					collision = false;
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
					for (int i = 0; i < vectorSize; i++)
					{
						for (int j = 0; j < allSprites.size() - vectorSize; j++)
						{
							if (spriteVector[i].getPosition().x + blockSize == allSprites[j].getPosition().x && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
							{
								collision = true;
							}
						}
					}
					if (collision == false)
					{
						blockVector[locationNumber]->moveRight();
					}
					collision = false;
				}
				positionCounter = 0;
			}

			else if (event.key.code == sf::Keyboard::Down && clock.getElapsedTime().asMicroseconds() < 500000)
			{
				for (int i = 0; i < vectorSize; i++)
				{
					if (spriteVector[i].getPosition().y + 20 > 18 * blockSize)
					{
						collision = true;
					}
					else
					{
						positionCounter++;
					}
				}
				if (positionCounter == vectorSize)
					for (int i = 0; i < vectorSize; i++)
					{
					for (int j = 0; j < allSprites.size() - vectorSize; j++)
					{
						if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x && spriteVector[i].getPosition().y + blockSize == allSprites[j].getPosition().y)
						{
							collision = true;
						}
						else if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
						{
							this->game->pushState(new MainMenu(this->game));
							std::cout << "Back to main menu\n";
							return;
						}
					}
					}
				if (collision == false)
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

void MultiplayerState::update(const float dt)
{
	if (newBlock == true)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			allSprites.push_back(spriteVector[i]);
			newBlock = false;
		}
	}
	else if (newBlock == false)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			allSprites.erase(allSprites.end() - 1 - i);
			allSprites.push_back(spriteVector[i]);
		}
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (collision == true)
		{
			clock.restart();
			collision = false;
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
			newBlock = true;

			break;
		}
	}
	if (clock.getElapsedTime().asMicroseconds() >= 500000)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if (spriteVector[i].getPosition().y + 20 > 18 * blockSize)
			{
				collision = true;
			}
			for (int j = 0; j < allSprites.size() - vectorSize; j++)
			{
				if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x && spriteVector[i].getPosition().y + blockSize == allSprites[j].getPosition().y)
				{
					collision = true;
				}
				else if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
				{
					this->game->pushState(new MainMenu(this->game));
					std::cout << "Back to main menu\n";
					return;
				}
			}
		}
		if (collision == false)
		{
			blockVector[locationNumber]->moveDown();
			clock.restart();
		}
	}

	if (clock.getElapsedTime().asMicroseconds() >= 500000)
	{
		blockVector[locationNumber]->moveDown();
		clock.restart();
	}

	if (newBlock == true)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			allSprites.push_back(spriteVector2[i]);
			newBlock = false;
		}
	}
	else if (newBlock == false)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			allSprites.erase(allSprites.end() - 1 - i);
			allSprites.push_back(spriteVector2[i]);
		}
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (collision = true)
		{
			clock.restart();
			collision = false;
			randomBlock2 = randomBlock;
			blockVector2.push_back(block);
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
			pointsText2.setString(ss.str());
			newBlock = true;
			break;
		}
	}

	if (clock.getElapsedTime().asMicroseconds() >= 500000)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if (spriteVector2[i].getPosition().y + 20 > 18 * blockSize)
			{
				collision = true;
			}
			for (int j = 0; j < allSprites.size() - vectorSize; j++)
			{
				if (spriteVector2[i].getPosition().x == allSprites[j].getPosition().x && spriteVector2[i].getPosition().y + blockSize == allSprites[j].getPosition().y)
				{
					collision = true;
				}
				else if (spriteVector2[i].getPosition().x == allSprites[j].getPosition().x && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
				{
					this->game->pushState(new MainMenu(this->game));
					std::cout << "Back to main menu\n";
					return;
				}
			}
		}
		if (collision == false)
		{
			blockVector2[locationNumber]->moveDown();
			clock.restart();
		}
	}
}


MultiplayerState::~MultiplayerState()
{
}
