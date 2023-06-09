#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <cstdlib>
#include "Map.h"



class BaseEntity {

protected:
	int speedX;
	int speedY;
	int x;
	int y;
	int dimX;
	int dimY;
	void draw();
	Hitbox hitbox;
	Map map;   
public:
	Map getMap();
	BaseEntity(int x=1, int y=1,int dimX=1,int dimY=1,int speedX=1,int speedY=1):hitbox(x,dimX, y,dimY) {
		setX(x);
		setY(y);
		setspeedX(speedX);
		setspeedY(speedY);
		this->dimX = dimX;
		this->dimY = dimY;
	}
	void setX(int x) {
		this->x = x;

	}
	void setY(int y) {
		this->y = y;

	}
	void setspeedX(int x) {
		this->speedX = x;

	}
	void setspeedY(int y) {
		this->speedY = y;

	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getDimX() {
		return dimX;
	}
	int getDimY() {
		return dimY;
	}
	void move(const float dirX, const float dirY);
	Hitbox *getHitbox();
	bool checkiMap();
	bool checkInside(Hitbox &a);
};


