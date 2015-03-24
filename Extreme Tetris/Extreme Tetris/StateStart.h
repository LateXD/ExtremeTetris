#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"
#include "Blocks.h"
#include "MainMenu.h"
#include "PlayField.h"

class StateStart : public GameState
{
public:
	StateStart(Game* game);
	~StateStart();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();
	
private:
	//sf::View view;
	int xPos = 3, yPos = 0, number = 0;
	Blocks block;
	sf::Clock clock;
	sf::Sprite frame;
	sf::Texture frameTexture;
	std::vector<sf::Sprite> vector;
	std::vector<Blocks*>blockVector;
	PlayField field;
	PlayField* fieldPointer = &field;
};
#endif;

