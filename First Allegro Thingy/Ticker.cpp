#include "Ticker.h"

void Ticker::ticker()
{
	if (tick <= 128) {
		tick += 1;
	}
	else tick = 0;
}

int Ticker::getTick()
{
	return tick;
}

void Ticker::setTick(int tick)
{
	this->tick = tick;
};
