#pragma once

#include "Bullet.h"
class Enemy: public BaseEntity
{
public:
	
	Enemy();
	void automatedMover();
	void move(const float dirX, const float dirY);
	void draw();
private:
	float dx = 0;
	float dy = 0;
	float angle;
	int timer = 120;
	int dimX = 30;
	int dimY = 30;
	int speed = 3;
	Collision hitbox;

};

