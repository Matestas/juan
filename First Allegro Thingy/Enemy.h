#pragma once

#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	Enemy(int x, int y, int speed);
	void automatedMover();
	void move(const float dirX, const float dirY);
	void draw();
	float getdx();
	float getdy();
	Collision getHitbox();
	void setdy(float dy);
	void setdx(float dx);
	
private:
	float dx = 0.00f;
	float dy = 0.00f;

	float angle; // can be removed
	int timer = 0;// can be removed
	int dimX = 30;
	int dimY = 30;
	int speed = 5;
	Collision hitbox;
	

};

