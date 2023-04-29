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

#ifndef LOADERS_H
#define LOADERS_H
#include "Loaders.h"
#endif


class Player : public BaseEntity {
public:
	Player();
	~Player();
	//void spawn();
	void fire_bullet();
	void update();
	void move(const int, const int);
	std::vector<Bullet>& getbullets();
	ALLEGRO_BITMAP* Ship = NULL;

private:
	std::vector<Bullet> bullets;

	int health = 10;
	bool speedBoost = false;
	void draw();


};