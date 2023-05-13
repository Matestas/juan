#pragma once
#include "Ticker.h"
#include "Bullet.h"
#define MAX_BULLETS 30
class Gun
{
public:
	Gun(float fireRate = 10, int damage = 10, ALLEGRO_SAMPLE* bulletSound = NULL, ALLEGRO_BITMAP* bulletImage = NULL); // fuck you
	ALLEGRO_BITMAP** getBulletImage();
	ALLEGRO_SAMPLE** getBulletSound();
	void setBulletSound(ALLEGRO_SAMPLE* sound);
	void setBulletImage(ALLEGRO_BITMAP* image);
	virtual void fire_bullet(int x, int y, Ticker tick);
	ALLEGRO_BITMAP** getBulletImage(int i);
	ALLEGRO_SAMPLE** getBulletSound(int i);
	void moveBullets();
    Bullet bullets[MAX_BULLETS];
	void resetbullets(bool hit);
protected:
	float fireRate; // SHOTS FIRED
	void loadBullets();
	ALLEGRO_SAMPLE* bulletSound;
	ALLEGRO_BITMAP* bulletImage;
	int damage;
	int bulletsFired;
};

