#pragma once
#include "Collision.h"

class Map
{
public:
	Map();
	~Map();
	bool operator==(Hitbox& t);
	Hitbox limit;
private:
	

	

};

