#pragma once
#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	Enemy(int x, int y, int speedX,int speedY, int moveType = 1,int dimX= 50,int dimY=50);
	float dy;
	float dx;
	void draw();
	bool limit();
	int moveType;
private:
	

};

