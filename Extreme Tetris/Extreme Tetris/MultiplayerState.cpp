#include "MultiplayerState.h"

MultiplayerState::MultiplayerState(Game* game)
{
	this->game = game;

	fieldTexture = game->setTexture(fieldTexture, "..\\Graphics\\Frame.png");
	pointsFieldTexture = game->setTexture(pointsFieldTexture, "..\\Graphics\\Frame2.png");
	bgTexture = game->setTexture(bgTexture, "..\\Graphics\\Background.png");
	font = game->setFont(font, "..\\Graphics\\8bitOperatorPlus8-Regular.ttf");

	// Setting up frames for blocks and other information
	field.setTexture(fieldTexture);
	field.setPosition(blockSize * 28, 0);
	field.setColor(sf::Color(red / 2, blue / 2, green / 2));
	bg.setTexture(bgTexture);
	bg.setPosition(blockSize * 29, blockSize);
	pointsField.setTexture(pointsFieldTexture);
	pointsField.setColor(sf::Color(red / 2, blue / 2, green / 2));
	pointsField.setPosition(blockSize * 20, 0);

	// Making of the first block and inserting it into a vector
	currentRandomBlock = randomBlock;
	blockVector.push_back(new Blocks(randomBlock));
	for (int i = 0; i < 28; i++)
	{
		blockVector[0]->moveRight();
	}
	randomBlock = rand() % 7 + 1;
	block = new Blocks(randomBlock);
	block->nextBlock(direction);
	for (int i = 0; i < 8; i++)
	{
		block->moveRight();
	}
	direction = false;
	for (int i = 0; i < blockVector.size(); i++)
	{
		spriteVector = blockVector[i]->getVector();
	}

	// Setting up text for points
	pointsText.setFont(font);
	pointsText.setColor(sf::Color::Black);
	pointsText.setCharacterSize(25);
	pointsText.setPosition(sf::Vector2f(blockSize * 26, blockSize * 8.60));
	levelText.setFont(font);
	levelText.setColor(sf::Color::Black);
	levelText.setCharacterSize(25);
	levelText.setPosition(sf::Vector2f(blockSize * 26, blockSize * 11.60));
	ss << points;
	pointsText.setString(ss.str());
	ss.clear();
	ss.str("");
	ss << level;
	levelText.setString(ss.str());
	if (red < 150 && blue < 150 && green < 150)
	{
		pointsText.setColor(sf::Color::White);
		levelText.setColor(sf::Color::White);
	}
	ss.clear();
	ss.str("");

	gameOverRectangle.setPosition(blockSize * 30, blockSize * 5);
	gameOverRectangle.setSize(sf::Vector2f(blockSize * 8, blockSize * 6));
	gameOverRectangle.setOutlineColor(sf::Color::Blue);
	gameOverRectangle.setOutlineThickness(2);
	gameOverText.setFont(font);
	gameOverText.setColor(sf::Color::Black);
	gameOverText.setCharacterSize(20);
	gameOverText.setPosition(blockSize * 31, blockSize * 6);
}

void MultiplayerState::draw(const float dt)
{
	// Clears screen and draws everything in order: background, frames, text, next block, all the other blocks
	game->window.draw(bg);
	game->window.draw(pointsField);
	game->window.draw(pointsText);
	game->window.draw(levelText);

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

void MultiplayerState::handleInput()
{
	if (gameOver == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			game->setGameOverBool(true);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			gameOver = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			// Moves your current block left while checking if it collides to another block or wall
			for (int i = 0; i < vectorSize; i++)
			{
				if (spriteVector[i].getPosition().x - blockSize > blockSize * 28)
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

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			// Moves your current block right while checking if it collides to another block or wall
			for (int i = 0; i < vectorSize; i++)
			{
				if (spriteVector[i].getPosition().x + blockSize < blockSize * 39)
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

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && clock.getElapsedTime().asMicroseconds() < 600000 / (level + 1))
		{
			// Moves your current block down while checking if it collides to another block or floor
			// If the block hits floor collision turns to true and another block is made in update section
			// If the block doesn't collide pointsCounter goes up providing you better points if you drop blocks at your own will
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

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period))
		{
			blockVector[locationNumber]->rotateClockwise(currentRandomBlock, allSprites);
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma))
		{
			blockVector[locationNumber]->rotateCounterClockwise(currentRandomBlock, allSprites);
		}
	}
}

void MultiplayerState::update(const float dt)
{
	// Inserts the next block in the vector or replaces the old one
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

	// Makes a new block and updates points
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
			newBlock = true;
			for (int i = 0; i < 8; i++)
			{
				block->moveRight();
			}
			for (int i = 0; i < 20; i++)
			{
				blockVector[locationNumber]->moveRight();
			}

			break;
		}
	}

	// Drops your current block according to your current level and quits the game if you reach the top or you somehow end up dropping a block on top of another block
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

void MultiplayerState::rowClearing()
{
	// Goes through allSprites vector finding blocks that should be removed or dropped down and gives you points according to how many rows you cleared at the same time
	for (int i = 0; i < blockSize * blockSize; i += blockSize)
	{
		for (int j = 0; j < allSprites.size(); j++)
		{
			if (clearRow == true && allSprites[j].getPosition().y == rowNumber)
			{
				allSprites[j].move(0, blockSize * 30);
				rowCounter++;
			}
			else if (clearRow == true && allSprites[j].getPosition().y < rowNumber)
			{
				allSprites[j].move(0, blockSize);
			}
			if (clearRow == false && allSprites[j].getPosition().y == i)
			{
				rowCounter++;
			}
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

	for (int i = 0; i < allSprites.size() - vectorSize; i += vectorSize)
	{
		if (allSprites[i].getPosition().y > blockSize * 30 && allSprites[i + 1].getPosition().y > blockSize * 30 && allSprites[i + 2].getPosition().y > blockSize * 30 && allSprites[i + 3].getPosition().y > blockSize * 30)
		{
			delete blockVector[i / vectorSize];
			blockVector.erase(blockVector.begin() + i / vectorSize);
			allSprites.erase(allSprites.begin() + i, allSprites.begin() + i + 4);
			locationNumber--;
			i = -vectorSize;
		}
	}
}

MultiplayerState::~MultiplayerState()
{
}
