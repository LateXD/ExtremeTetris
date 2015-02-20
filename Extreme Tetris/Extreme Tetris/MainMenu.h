#ifndef MAINMENU_H
#define MAINMENU_H

#define MAX_NUMBER_OF_ITEMS 4

#include "GameState.h"

class MainMenu : public GameState
{
public:
	MainMenu(Game* game);
	~MainMenu();

	//void Main(float width, float height);
	void draw(const float dt);
	void update(const float dt);
	void MoveUp();
	void MoveDown();
	int GetPressedItem();
	void handleInput();

protected:
	void onInitialize();
private:
	float width, height;
	sf::Font font;
	int selectedItemIndex = 1;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
};
#endif;

