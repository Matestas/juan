#pragma once
#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	Enemy(int x, int y, int speedX,int speedY);
	
	void draw();
	bool limit();
private:

};

