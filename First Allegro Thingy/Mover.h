#pragma once
#include "Enemy.h"
#include "Ticker.h"
class Mover
{
public:
	Mover() {}
	~Mover() {}
	Mover(int timer);
	void randomMover(Enemy& enemy, int dirX, int angleMinRange, int angleMaxRange);
	//void linearMover();
	//void curvedMover();
	//void trackedMover(Enemy& enemy, Player& player);
private:
	Ticker ticker;
	
};

