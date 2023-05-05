#include "Gun.h"

Gun::Gun(float fireRate,int angle,int fired,int damage, ALLEGRO_SAMPLE* bulletSound , ALLEGRO_BITMAP* bulletImage ){
	this->fireRate = fireRate;
	bulletAngle = angle;
	this->damage = damage;
	bulletsFired = fired;
	this->bulletSound = bulletSound;
	this->bulletImage = bulletImage;
}


ALLEGRO_BITMAP** Gun::getBulletImage(int i) {
	return bullets[i].getBulletImage();
}
ALLEGRO_SAMPLE** Gun::getBulletSound(int i) {
	return bullets[i].getBulletSound();
}
void Gun::fire_bullet() {
	al_play_sample(*getBulletSound(0), 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, 0);
}
void Gun::loadBullets() {
	for (int i = 1; i <= 8; i++) {
		this->bullets[i] = Bullet(bullets[0]);
	}
}
void Gun::moveBullets(Bullet bullets[]) {
	for (int i = 0; i < 10; i++) {
		bullets[i].move(1, 0);
	}
}

void Gun::setBulletSound(ALLEGRO_SAMPLE* sound) {
	bulletSound = sound;
}
void Gun::setBulletImage(ALLEGRO_BITMAP* image) {
	bulletImage = image;
}
ALLEGRO_BITMAP** Gun::getBulletImage() {
	return &bulletImage;
}
ALLEGRO_SAMPLE** Gun::getBulletSound() {
	return &bulletSound;
}