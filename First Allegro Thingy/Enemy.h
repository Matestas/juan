#pragma once

#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	Enemy(int x, int y, int speedX,int speedY);
	void automatedMover();
	void draw();
	float getdx();
	float getdy();
	void setdy(float dy);
	void setdx(float dx);
	bool limit();
private:
	float dx = 0.00f;
	float dy = 0.00f;

	float angle; // can be removed
	int timer = 0;// can be removed
	int dimX = 30;
	int dimY = 30;
	

};

