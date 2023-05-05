#include "Bullet.h"
#include "Loaders.h"


Bullet::Bullet(int x, int y) {
	
	this->x = x;
	this->y = y;
	this->speed = 60;
	isMoving = false;
}
Bullet::Bullet():BaseEntity(-1,-1) {
	isMoving = false;
	
}
Bullet::~Bullet() {
	
}
void Bullet::move(const int dirX, const int dirY) {
	if (isMoving) {
		this->x += (dirX * speed);
		this->y += (dirY * speed);
	}
}


void Bullet::draw() {

	al_draw_scaled_bitmap(bulletImage, 0, 0, 1083, 1060, x, y, 30, 30, 0);
}
void Bullet::ignite() {
	// charge animation here ( 10 frames maybe) 
	
	al_play_sample(bulletSound,1,0,1,ALLEGRO_PLAYMODE_ONCE,0);
	
}
Bullet::Bullet(Bullet& old) {
	this->x = old.x;
	this->y = old.y;
	this->isMoving = old.isMoving;
	this->speed = old.speed;
	this->bulletImage = old.bulletImage;
	this->bulletSound = old.bulletSound;
}

int Bullet::getspeed() {
	return speed;
}

void Bullet::hit() {
	if (checkhit()) {
		this->health -= 1;
	}

	// hit animation function here
}
void Bullet::setspeed(int speed) {
	this->speed = speed;
}
bool Bullet::checkhit() {

	// check which enemy hit and call beenhit function on the enemy hit, check if the enemy hit with a bullet is not hit again with the same bullet
	// , which can cause bugs with the perfuration mechanic
	return true;
}
void Bullet::setDamage(int damage){
	this->damage = damage;
}
void Bullet::setDimensions(int x,int y){
	dimx = x;
	dimy = y;
}
void Bullet::setPenetration(int hp){
	health = hp;
}


void Bullet::setBulletSound(Bullet ID,ALLEGRO_SAMPLE* sound) {
	ID.bulletSound = sound;
}
void Bullet::setBulletImage(Bullet ID,ALLEGRO_BITMAP* image) {
	ID.bulletImage = image;
}
ALLEGRO_BITMAP** Bullet::getBulletImage() {
	return &bulletImage;
}
ALLEGRO_SAMPLE** Bullet::getBulletSound() {
	return &bulletSound;
}