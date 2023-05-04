#pragma once
#include "Entities.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>

ALLEGRO_BITMAP* load_image(const char* filename, const char* image_ID);

ALLEGRO_SAMPLE* load_sample(const char* filename, const char* sample_ID);

class Bullet : public BaseEntity {
	
public:
	Bullet();
	Bullet(Bullet& old);
	~Bullet();
	Bullet(int, int);
	int getspeed();
	void setBulletImage(Bullet ID,ALLEGRO_BITMAP* image);
	void setBulletSound(Bullet ID,ALLEGRO_SAMPLE* sound);
	void hit();// hits the enemy
	void move(const int, const int);  // moves when isMoving
	
	ALLEGRO_BITMAP** getBulletImage();
	ALLEGRO_SAMPLE** getBulletSound();
	void ignite();    // firing
	bool checkhit(); // check if hits enemy
	void setspeed(int);
	void setDamage(int);
	void setDimensions(int,int);
	void setPenetration(int);
	int getdimX();
	int getdimY();
	int gunPosX;
	int gunPosY;
	private:
	
	int damage = 1;
	int health = 1;   // used for perfuration mechanics used in buffs
	int speed = 2;
	int dimX = 20;
	int dimY = 40;
	
	Collision hitbox;
	ALLEGRO_BITMAP* bulletImage = NULL;
	ALLEGRO_SAMPLE* bulletSound = NULL;
	void draw();
	bool isMoving = false;
	
	
};


