#pragma once
#include "Player.h"
#include "Enemy.h"
#
class Mover
{
public:
	Mover(int timer);
	void ticker();
	int getTick();
	void checkTick() {
		if (tick == 129) {
			std::cout << "now" << std::endl;
		}
	}
	void randomMover(Enemy& enemy, int dirX, int angleMinRange, int angleMaxRange);
	//void linearMover();
	//void curvedMover();
	//void trackedMover(Enemy& enemy, Player& player);
private:
	int tick = 0;
	
	
};

