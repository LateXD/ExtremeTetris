#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H

#include "GameState.h"

class OptionsState : public GameState
{
public:
	OptionsState(Game* game);
	~OptionsState();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

private:

	
};
#endif;

