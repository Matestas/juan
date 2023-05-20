#pragma once
#include <iostream>
class Ticker
{
public:
	Ticker() {
		tick = 0;
		cycle = 0;
	}
	void ticker();
	int getTick();
	int getCycle();
	void checkTick() {       //test function
		if (tick == 129) {
			//std::cout << "now" << std::endl;
		}
	}
	void setTick(int tick);
	void setCycle(int cycle);
private:
	int tick;
	int cycle;
};


