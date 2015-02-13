#ifndef STATESTART_H
#define STATESTART_H

#include "GameState.h"

class StateStart : public GameState
{
public:
	~StateStart();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

	StateStart(Game* game);
private:
	//sf::View view;
};
#endif;

