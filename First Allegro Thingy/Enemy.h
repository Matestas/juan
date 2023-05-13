#pragma once
#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	Enemy(int x, int y, int speedX,int speedY);
	
	void draw();
	float getdx();
	float getdy();
	void setdy(float dy);
	void setdx(float dx);
	bool limit();
private:
	float dx = 0.00f;
	float dy = 0.00f;
	int dimX = 30;
	int dimY = 30;
	

};

