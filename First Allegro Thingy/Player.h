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
#include "RocketLauncher.h"
#include "Shotgun.h"
#include"laser.h"
#include"Enemy.h"
#ifndef LOADERS_H
#define LOADERS_H
#include "Loaders.h"
#endif

using namespace std;


class Player : public BaseEntity {
	

public:
	Player(int dimX=68,int dimY=20);
	~Player();
	void changeWeapon(int w);
	void update(vector<Enemy*> enemy);
	ALLEGRO_BITMAP* Ship = NULL;
	void setShipImage(ALLEGRO_BITMAP* image);
	Gun* weaponInUse;
	vector<Gun*> guns;
	void checkBullets(Hitbox hit);
private:
	int dimX;
	int dimY;
	int health = 10;
	MachineGun* mGun;
	RocketLauncher* RLauncher;
	Shotgun* shotgun; 
	Laser* laser; 

	bool speedBoost = false;
	void draw();


};


