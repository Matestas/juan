
#include "Player.h"

Player::Player(int dimX,int dimY) : BaseEntity(0, 0, dimX, dimY){
	
	speedX = 15;
	speedY = 15;
	health = 10;
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
	health = 10;

}
void Player::move(const float dirX, const float dirY) {
	this->x += (dirX * speedX);
	this->y += (dirY * speedY);
	animate(dirX);
	hitbox.move(x, y);
	if (!checkiMap()) {

		this->x -= (dirX * speedX);
		this->y -= (dirY * speedY);
		hitbox.move(x, y);
	};
}
Player::Player(Player& old)
{
	this->x = old.x;
	this->y = old.y;
	this->speedX = old.speedX;
	this->speedY = old.speedY;
	this->dimX = old.dimX;
	this->dimY = old.dimY;
	this->mGun = old.mGun;
	this->shotgun = old.shotgun;
	this->laser = old.laser;
	this->RLauncher = old.RLauncher;
	this->guns = old.guns;
	this->weaponInUse = old.weaponInUse;
	this->health = 10;
	this->speedBoost = old.speedBoost;
	this->Ship = old.Ship;
	this->hitbox = old.hitbox;
	this->ships = old.ships;
	this->totalExplosion = old.totalExplosion;
	
}
void Player::resetPlayer(Player& old){
	this->x = old.x;
	this->y = old.y;
	this->speedX = old.speedX;
	this->speedY = old.speedY;
	this->dimX = old.dimX;
	this->dimY = old.dimY;
	this->mGun = old.mGun;
	this->shotgun = old.shotgun;
	this->laser = old.laser;
	this->RLauncher = old.RLauncher;
	this->guns = old.guns;
	this->weaponInUse = old.weaponInUse;
	this->health = old.health;
	this->speedBoost = old.speedBoost;
	this->hitbox = old.hitbox;
	this->totalExplosion = old.totalExplosion;
}
void Player::setTotalExplosion(ALLEGRO_BITMAP* totalExplosion)
{
	this->totalExplosion = totalExplosion;
}



void  Player::setShip(ALLEGRO_BITMAP* image) {
	Ship = image;
}
void Player::checkBullets(Hitbox &hit)
{
	for (auto gun : guns) {
		gun->resetbullets(hit);
	}
}
void Player::setPlayerImages(std::vector <ALLEGRO_BITMAP*> ships)
{
	this->ships = ships;
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
	
	for (auto gun : guns) {
		gun->drawBullets();
	}
}

bool Player::checkCollision(Hitbox& x)
{
	if (hitbox == x)
	{
		getDamaged();
		return true;
	}if (checkInside(x)) {
		getDamaged();
		return true;
	}
	return false;
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

void Player::animate(const float dirX)
{
	if (dirX > 0) {
		setShip(ships[1]);
	}
	if (dirX < 0) {
		setShip(ships[2]);
	}
	else {
		setShip(ships[0]);
	}
}
