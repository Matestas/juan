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
#include "Enemy.h"
#include "Ticker.h"


class Bullet : public BaseEntity {
	
public:
	Bullet();
	Bullet(Bullet& old);
	~Bullet();
	Bullet(int x, int y);
	int getspeedX();
	int getspeedY();
	void explode(Ticker ticker);
	
	void move();  // moves when isMoving
	void moveto(const int, const int);
	ALLEGRO_BITMAP* explosion;   // cada explosao [32,32]

	int tick1 =0;
	bool checkhit(Hitbox &x); // check if hits enemy
	void setspeed(int,int);
	void setDimensions(int,int);
	bool isMoving;
	void draw();
	private:
	
	
	
	
	
};


