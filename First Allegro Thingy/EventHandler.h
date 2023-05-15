#pragma once
#include "Player.h"
#include "Menu.h"
class EventHandler
{
private:
	int currentHover;
	
public:
	EventHandler(bool inMenu = true, int currentHover = 0);
	void checkPlayerShoot(ALLEGRO_EVENT& event, Player& Player, Ticker tick);
	void readMovementKeys(ALLEGRO_EVENT& event);
	void checkCloseTab(ALLEGRO_EVENT& event);
	void movePlayer(Player& Player);
	void changeMenuButton(std::vector <Menu*> menubuttons, ALLEGRO_EVENT& event);
	void chooseMenuButton(Menu* menuButtons, ALLEGRO_EVENT& event);
	void switchScreen(std::vector <Menu*> menuButtons);
	int getCurrentHover();
	void backToMenu(ALLEGRO_EVENT);

	void test(Menu* menuButton, ALLEGRO_EVENT& event);
	bool inMenu;
	bool inEndless;
	bool isFirstBoot;
	bool isRunning;
	bool juanIsPlaying;
	bool bgmIsPlaying;
};

