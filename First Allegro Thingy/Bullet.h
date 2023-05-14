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
	int getspeedX();
	int getspeedY();
	void setBulletImage(Bullet ID,ALLEGRO_BITMAP* image);
	void setBulletSound(Bullet ID,ALLEGRO_SAMPLE* sound);
	void move();  // moves when isMoving
	void moveto(const int, const int);
	
	ALLEGRO_BITMAP** getBulletImage();
	ALLEGRO_SAMPLE** getBulletSound();
	void ignite();    // firing
	bool checkhit(Hitbox x); // check if hits enemy
	void setspeed(int,int);
	void setDimensions(int,int);
	bool isMoving;
	void draw();
	private:
	ALLEGRO_BITMAP* bulletImage = NULL;
	ALLEGRO_SAMPLE* bulletSound = NULL;
	
	
	
	
};


