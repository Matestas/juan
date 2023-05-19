
#include "Player.h"

Player::Player(int dimX,int dimY) : BaseEntity(0, 0, dimX, dimY){
	
	speedX = 20;
	speedY = 20;
	this->dimX = dimX;
	this->dimY = dimY;
	mGun = new MachineGun();
	RLauncher = new RocketLauncher();
	shotgun = new Shotgun();
	laser = new Laser();
	guns.push_back(mGun);
	guns.push_back(RLauncher);
	guns.push_back(shotgun);
	guns.push_back(laser);
	weaponInUse = laser;
}




void  Player::setShipImage(ALLEGRO_BITMAP* image) {
	Ship = image;
}
void Player::checkBullets(Hitbox &hit)
{
	for (auto gun : guns) {
		gun->resetbullets(hit);
	}
}
bool Player::checkGunHit(Hitbox &x)
{
	for (auto gun : guns) {
		if (gun->checkhit(x)) {
			return true;
		}
	}
	return false;
}
// frame update
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 3,11, 27, 9, x, y, dimX, dimY, 0);
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(250, 250, 25), 2);
}

Player::~Player() {

}
void Player::changeWeapon(int w)
{
	switch (w)
	{
	case 0:
		weaponInUse = laser;
		std::cout << "laser";
		break;
	case 1:
		weaponInUse = mGun;
		std::cout << "mgun";
		break;
	case 2:
		weaponInUse = shotgun;
		std::cout << "shotgun";
		break;
	case 3:
		weaponInUse = RLauncher;
		std::cout << "Rlauncher";
		break;
	}
}
void Player::update() {
	draw();
	for (auto gun : guns) {
		gun->moveBullets();
	}

}
