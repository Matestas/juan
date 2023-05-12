#pragma once
#include "Entities.h"

class Bot: public BaseEntity
{
public:
	Bot(int x, int y) : BaseEntity(x, y){

	}
	Bot(int x, int y, int dimX, int dimY, int speedX, int speedY, int tick, int moveType) : BaseEntity(x, y, dimX, dimY, speedX, speedY) {

	};
	
private:
	
};

