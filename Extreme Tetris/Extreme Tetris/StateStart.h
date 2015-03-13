#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"
#include "Blocks.h"

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
	Blocks block;
	std::vector<sf::Sprite> vector;
};
#endif;

