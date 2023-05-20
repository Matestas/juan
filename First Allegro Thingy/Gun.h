#pragma once
#include <vector>
#include "Ticker.h"
#include "Bullet.h"
#include "Enemy.h"
#define MAX_BULLETS 30
class Gun
{
public:
	Gun(float fireRate = 10, int damage = 10, ALLEGRO_SAMPLE* bulletSound = NULL, ALLEGRO_BITMAP* bulletImage = NULL); // fuck you
	ALLEGRO_BITMAP* getBulletImage();
	ALLEGRO_SAMPLE* getGunSound();
	void setGunSound(ALLEGRO_SAMPLE* sound);
	void setBulletImage(ALLEGRO_BITMAP* image);
	void setExplosion(ALLEGRO_BITMAP* image);
	virtual void fire_bullet(int x, int y, Ticker tick);
	
	void moveBullets();
    Bullet bullets[MAX_BULLETS];
	void resetbullets(Hitbox hit);
	bool checkhit(Hitbox &x);
	void drawBullets();
	int getDamage();
protected:
	float fireRate; // SHOTS FIRED
	void loadBullets();
	ALLEGRO_SAMPLE* gunSound;
	ALLEGRO_BITMAP* bulletImage;
	
	int damage;
	int bulletsFired;
};

