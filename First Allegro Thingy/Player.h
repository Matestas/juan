#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include "Bullet.h"
#include "MachineGun.h"
#include "Collision.h"

#ifndef LOADERS_H
#define LOADERS_H
#include "Loaders.h"
#endif


class Player : public BaseEntity {
	

public:
	Player(int dimX=68,int dimY=20);
	~Player();
	
	void update();
	ALLEGRO_BITMAP* Ship = NULL;
	void setShipImage(ALLEGRO_BITMAP* image);
	//void changeweapon();
	Gun* weapon;
private:
	int dimX;
	int dimY;
	int health = 10;
	

	bool speedBoost = false;
	void draw();


};


