#include "Ticker.h"

void Ticker::ticker()
{
	if (tick <= 128) {		//adds 1 to the tick or adds to the cycle
		tick += 1;
	}
	else {
		tick = 0;
		cycle += 1;
	}
}

int Ticker::getTick()
{
	return tick;	//returns the tick
}

int Ticker::getCycle()
{
	return cycle;  //returns cycle
}

void Ticker::setTick(int tick)
{
	this->tick = tick;	//sets the tick
}
void Ticker::setCycle(int cycle)
{
	this->cycle = cycle;	//sets the cicle the tick is in
}
;
