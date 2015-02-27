#ifndef OPTIONSSTATE_H
#define OPTIONSSTATE_H

#define OPTIONS_ITEMS 3

#include "GameState.h"

class OptionsState : public GameState
{
public:
	OptionsState(Game* game);
	~OptionsState();

	void draw(const float dt);
	void update(const float dt);
	void MoveUp();
	void MoveDown();
	void handleInput();
	int GetPressedItem();

protected:
	void onInitialize();
private:
	float width, height;
	int selectedItemIndex = 1;
	sf::Font font;
	sf::Text options[OPTIONS_ITEMS];
	
};
#endif;

