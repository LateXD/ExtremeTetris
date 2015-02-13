#ifndef MAINMENU_H
#define MAINMENU_H

#include "GameState.h"

class MainMenu : public GameState
{
public:
	~MainMenu();

	void draw(const float dt);
	void update(const float dt);
	void handleInput();

	MainMenu(Game* game);

private:
	sf::View gameView;
	sf::View menuView;
};
#endif;

