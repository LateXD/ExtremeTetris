#include "InverseState.h"

// SingleplayerState with some changes to make it a new game mode. Changes have been commented below.

InverseState::InverseState(Game* game)
{
	this->game = game;
}

InverseState::~InverseState()
{
}

void InverseState::onInitialize()
{
	fieldTexture = game->setTexture(fieldTexture, "..\\Graphics\\Frame.png");
	pointsFieldTexture = game->setTexture(pointsFieldTexture, "..\\Graphics\\Frame2.png");
	bgTexture = game->setTexture(bgTexture, "..\\Graphics\\Background.png");
	font = game->setFont(font, "..\\Graphics\\8bitOperatorPlus8-Regular.ttf");

	bg.setTexture(bgTexture);
	bg.setPosition(blockSize, blockSize);

	field.setTexture(fieldTexture);
	field.setColor(sf::Color(red, blue, green));

	pointsField.setTexture(pointsFieldTexture);
	pointsField.setColor(sf::Color(red, blue, green));
	pointsField.setPosition(blockSize * 12, 0);

	pointsText.setFont(font);
	pointsText.setCharacterSize(25);
	pointsText.setPosition(sf::Vector2f(blockSize * 17.75, blockSize * 8.60));

	levelText.setFont(font);
	levelText.setCharacterSize(25);
	levelText.setPosition(sf::Vector2f(blockSize * 17.75, blockSize * 11.60));

	ss << points;
	pointsText.setString(ss.str());
	ss.clear();
	ss.str("");
	ss << level;
	levelText.setString(ss.str());
	ss.clear();
	ss.str("");

	controlsText.setFont(font);
	controlsText.setCharacterSize(12);
	controlsText.setPosition(blockSize * 13.2, blockSize * 15.25);
	controlsText.setString("Left: A\nRight: D\nDown: S");

	if (red > 100 && blue > 100 && green > 100)
	{
		pointsText.setColor(sf::Color::Black);
		levelText.setColor(sf::Color::Black);
		controlsText.setColor(sf::Color::Black);
	}

	gameOverRectangle.setPosition(blockSize * 2, blockSize * 5);
	gameOverRectangle.setSize(sf::Vector2f(blockSize * 8, blockSize * 6));
	gameOverRectangle.setOutlineColor(sf::Color::Blue);
	gameOverRectangle.setOutlineThickness(2);

	gameOverText.setFont(font);
	gameOverText.setColor(sf::Color::Black);
	gameOverText.setCharacterSize(20);
	gameOverText.setPosition(blockSize * 3, blockSize * 6);

	currentRandomBlock = randomBlock;
	blockVector.push_back(new Blocks(randomBlock));
	randomBlock = rand() % 7 + 1;
	block = new Blocks(randomBlock);
	block->nextBlock(direction);
	direction = false;
	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
	}
}

void InverseState::draw(const float dt)
{
	game->window.draw(bg);
	game->window.draw(pointsField);
	game->window.draw(pointsText);
	game->window.draw(levelText);
	game->window.draw(controlsText);

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

	game->window.draw(field);

	if (gameOver == true)
	{
		ss << "Game Over!\nPoints:\n" << points << "\nPress enter.";
		gameOverText.setString(ss.str());
		ss.clear();
		ss.str("");
		game->window.draw(gameOverRectangle);
		game->window.draw(gameOverText);
	}
}

void InverseState::handleInput()
{
	if (gameOver == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			if (game->getMultiplayerStart() == true)
			{
				game->setGameOverBool(true);
			}
			else
			{
				game->multiplayerStart(false);
				game->popState();
				return;
			}
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameOver = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			// Moves your dropped blocks left while checking if they collide to the dropping block.
			for (int i = 0; i < vectorSize; i++)
			{
				for (int j = 0; j < allSprites.size() - vectorSize; j++)
				{
					if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x - blockSize && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
					{
						collision = true;
					}
				}
			}
			if (collision == false)
			{
				for (int i = 0; i < blockVector.size() - 1; i++)
				{
					blockVector[i]->moveLeft();
				}
			}
			collision = false;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			// Moves your dropped blocks right while checking if they collide to the dropping block.
			for (int i = 0; i < vectorSize; i++)
			{
				for (int j = 0; j < allSprites.size() - vectorSize; j++)
				{
					if (spriteVector[i].getPosition().x == allSprites[j].getPosition().x + blockSize  && spriteVector[i].getPosition().y == allSprites[j].getPosition().y)
					{
						collision = true;
					}
				}
			}
			if (collision == false)
			{
				for (int i = 0; i < blockVector.size() - 1; i++)
				{
					blockVector[i]->moveRight();
				}
			}
			collision = false;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && clock.getElapsedTime().asMicroseconds() < 600000 / (level + 1))
		{
			// Moves the dropping block down while checking if it collides to another block or floor.
			// If the block hits floor collision turns to true and another block is made in update section.
			// If the block doesn't collide pointsCounter goes up providing you better points if you drop blocks at your own will.
			for (int i = 0; i < vectorSize; i++)
			{
				if (spriteVector[i].getPosition().y + blockSize > 18 * blockSize)
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
						gameOver = true;
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
	}
}

void InverseState::update(const float dt)
{
	// Updates allSprites vector by clearing it and inserting new information.

	allSprites.erase(allSprites.begin(), allSprites.end());
	for (int i = 0; i < blockVector.size(); i++)
	{
		blockVector[i]->seperateBlocks();
		spriteVector = blockVector[i]->getVector();
		for (int j = 0; j < vectorSize; j++)
		{
			allSprites.push_back(spriteVector[j]);
		}
	}

	for (int i = 0; i < vectorSize; i++)
	{
		if (collision == true && gameOver == false)
		{
			clock.restart();
			collision = false;
			currentRandomBlock = randomBlock;
			blockVector.push_back(block);
			block->nextBlock(direction);
			direction = true;
			rowClearing();
			randomBlock = rand() % 7 + 1;
			block = new Blocks(randomBlock);
			block->nextBlock(direction);
			direction = false;
			points += pointsCounter + rowPoints;
			rowPoints = 0;
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

			// Rotates the block in any of its possible position
			if (randomBlock == 2 || randomBlock == 3 || randomBlock == 4)
			{
				randomRotation = rand() % 2 + 1;
				for (int j = 0; j < randomRotation; j++)
				{
					block->rotateClockwise(randomBlock, allSprites);
				}
			}
			else if (randomBlock == 5 || randomBlock == 6 || randomBlock == 7)
			{
				randomRotation = rand() % 4 + 1;
				for (int j = 0; j < randomRotation; j++)
				{
					block->rotateClockwise(randomBlock, allSprites);
				}
			}
			break;
		}
	}

	if (clock.getElapsedTime().asMicroseconds() >= 600000 / (level + 1) && gameOver == false)
	{
		for (int i = 0; i < vectorSize; i++)
		{
			if (spriteVector[i].getPosition().y + blockSize > 18 * blockSize)
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
					gameOver = true;
				}
			}
		}
		if (collision == false)
		{
			blockVector[locationNumber]->moveDown();
			clock.restart();
		}
	}
}

void InverseState::rowClearing()
{
	for (int i = 0; i < blockSize * blockSize; i += blockSize)
	{
		for (int j = 0; j < blockVector.size(); j++)
		{
			rowCounter = blockVector[j]->clearBlocks(clearRow, rowNumber, rowCounter, i);
			if (clearRow == false && rowCounter == 10)
			{
				rowNumber = i;
				clearRow = true;
				rowCounter = 0;
			}
			else if (clearRow == true && rowCounter == 10)
			{
				rowsCleared++;
				if (rowsCleared % 10 == true && rowsCleared != 1 && level < 9)
				{
					level++;
					ss.clear();
					ss.str("");
					ss << level;
					levelText.setString(ss.str());
				}
				rowNumber = 0;
				rowCounter = 0;
				clearRow = false;
				j = -1;
				if (rowPoints == 0)
				{
					rowPoints = 40 * (level + 1);
				}
				else if (rowPoints == 40)
				{
					rowPoints = 100 * (level + 1);
				}
				else if (rowPoints == 100)
				{
					rowPoints = 300 * (level + 1);
				}
				else if (rowPoints == 300)
				{
					rowPoints = 1200 * (level + 1);
				}
			}
		}
		rowCounter = 0;
	}
	clearRow = false;

	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
		if (spriteVector[0].getPosition().y > blockSize * 30 && spriteVector[1].getPosition().y > blockSize * 30 && spriteVector[2].getPosition().y > blockSize * 30 && spriteVector[3].getPosition().y > blockSize * 30)
		{
			delete blockVector[i];
			blockVector.erase(blockVector.begin() + i);
			locationNumber--;
			i = -vectorSize;
		}
	}
}