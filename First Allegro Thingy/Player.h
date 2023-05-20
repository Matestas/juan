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


using namespace std;


class Player : public BaseEntity {
	

public:
	Player(int dimX=68,int dimY=20);
	void move(const float dirX, const float dirY);
	Player(Player& old);
	~Player();
	void changeWeapon(int w);
	void update();
	void animate(const float dirX);
	void setShip(ALLEGRO_BITMAP* image);
	Gun* weaponInUse;
	vector<Gun*> guns;
	void checkBullets(Hitbox &hit);
	bool checkGunHit(Hitbox &x);
	void resetPlayer(Player& old);
	void draw();
	bool checkCollision(Hitbox& x);
	void setPlayerImages(std::vector <ALLEGRO_BITMAP*> Ships);
	void getDamaged() {
		health-=1;
	}
	void setTotalExplosion(ALLEGRO_BITMAP* totalExplosion);
	std::vector < ALLEGRO_BITMAP*> ships;
	int health;
private:
	int dimX;
	int dimY;
	ALLEGRO_BITMAP* totalExplosion;
	ALLEGRO_BITMAP* Ship = NULL;
	MachineGun* mGun;
	RocketLauncher* RLauncher;
	Shotgun* shotgun; 
	Laser* laser; 

	bool speedBoost = false;
	


};


