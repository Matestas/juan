#pragma once
#include "Collision.h"

class Map
{
public:
	Map();
	~Map();
	bool operator==(Collision& t);
	Collision limit;
private:
	

	

};

