#pragma once
#include <iostream>
class Ticker
{
public:
	Ticker() {
		tick = 0;
	}
	void ticker();
	int getTick();
	void checkTick() {       
		if (tick == 129) {
			//std::cout << "now" << std::endl;
		}
	}
	void setTick(int tick);
private:
	int tick;
};


