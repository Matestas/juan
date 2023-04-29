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
	friend void moveall(std::vector<Bullet>&bullets);
	friend void update(std::vector<Bullet>&bullets);
	friend void limit(std::vector<Bullet>& bullets);   // screen limiter
public:
	Bullet();
	~Bullet();
	Bullet(int, int);
	int getspeed();
	  
	void hit();
	void move(const int, const int);
	// hits the enemy
	void ignite();    // firing
	bool checkhit(); // check if hits enemy
	ALLEGRO_BITMAP* common_bullet = NULL;
	ALLEGRO_SAMPLE* juan_effect = NULL;
	private:
	int damage = 1;
	int health = 1;   // used for perfuration mechanics used in buffs
	int speed = 2;
	void setspeed();
	void draw();
	
	
};


