#pragma once
#include "Player.h"
#include "Menu.h"
#include "MenuHandler.h"
class EventHandler
{

	
public:
	EventHandler();
	void checkPlayerShoot(ALLEGRO_EVENT& event, Player& Player, Ticker tick);
	void readMovementKeys(ALLEGRO_EVENT& event);
	void checkCloseTab(ALLEGRO_EVENT& event, MenuHandler& menuHandler);
	void movePlayer(Player& Player);


	


	bool isRunning;

};





