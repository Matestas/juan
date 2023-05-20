#include "Ticker.h"

void Ticker::ticker()
{
	if (tick <= 128) {
		tick += 1;
	}
	else {
		tick = 0;
		cycle += 1;
	}
}

int Ticker::getTick()
{
	return tick;
}

int Ticker::getCycle()
{
	return cycle;
}

void Ticker::setTick(int tick)
{
	this->tick = tick;
}
void Ticker::setCycle(int cycle)
{
	this->cycle = cycle;
}
;
