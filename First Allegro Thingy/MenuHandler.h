#pragma once
#include "Menu.h"
#include <vector>
class MenuHandler
{
public:
	MenuHandler();
	void changeMenuButton(std::vector <MenuButton*> menubuttons, ALLEGRO_EVENT& event);
	void chooseMenuButton(MenuButton* menuButtons, ALLEGRO_EVENT& event);
	void switchScreen(std::vector <MenuButton*> menuButtons);
	int getCurrentHover();
	bool backToMenu(ALLEGRO_EVENT&event);
	void test(MenuButton* menuButton, ALLEGRO_EVENT& event);
	void setCurrentHover(int currentHover);
	bool inMenu;
	bool inEndless;
	bool inHallOfFame;
	bool isFirstBoot;
	bool isRunning;
	bool inMainMenu;
	bool juanIsPlaying;
	bool bgmIsPlaying;
protected:

	int currentHover;
	
};

class MainMenu : public MenuHandler {

public:
	MainMenu(){//default constructor
		this->inMenu = false;
		this->inEndless = false;
		this->inMainMenu = true;
		this->inHallOfFame = false;
		this->currentHover = 0;

	}
	void switchScreen(std::vector <MenuButton*> menuButtons,MenuHandler& menuHandler);
	bool backToMenu(ALLEGRO_EVENT &event, MenuHandler& menuhandler);
	bool restartGame();
};

