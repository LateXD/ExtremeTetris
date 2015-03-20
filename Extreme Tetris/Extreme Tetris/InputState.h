#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#define INPUT_ITEMS 6

#include "GameState.h"

class InputState : public GameState
{
public:
	InputState(Game* game);
	~InputState();

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
	sf::Text input[INPUT_ITEMS];
};
#endif;
