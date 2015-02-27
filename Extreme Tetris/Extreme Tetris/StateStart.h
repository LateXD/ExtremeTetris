#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"

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
};
#endif;

