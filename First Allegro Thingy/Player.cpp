
#include "Player.h"

Player::Player(int dimX,int dimY) : BaseEntity(0, 0, dimX, dimY){ //constructor with default variables
	
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
void Player::move(const float dirX, const float dirY) {	//moves the player
	this->x += (dirX * speedX);
	this->y += (dirY * speedY);
	animate(dirX);
	hitbox.move(x, y);
	if (!checkiMap()) {	//checks if the player is moving outside the map and resets the movement if true

		this->x -= (dirX * speedX);
		this->y -= (dirY * speedY);
		hitbox.move(x, y);
	};
}
Player::Player(Player& old) //copy constructor
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
	
	
}
void Player::resetPlayer(Player& old){		//coppies the default player to the current player
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

}




void  Player::setShip(ALLEGRO_BITMAP* image) {
	Ship = image;		//set the current ship png
}
void Player::checkBullets(Hitbox &hit)
{
	for (auto gun : guns) {		//resets bullets that arent moving
		gun->resetbullets(hit);
	}
}
void Player::setPlayerImages(std::vector <ALLEGRO_BITMAP*> ships)
{
	this->ships = ships;	//sets the png to the various states of the shit
}
bool Player::checkGunHit(Hitbox &x)
{
	for (auto gun : guns) {
		if (gun->checkhit(x)) { //checks if the bullets of the guns hit the targets
			return true;
		}
	}
	return false;
}
// frame update
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 3,11, 27, 9, x, y, dimX, dimY, 0); //draws the png
	
	for (auto gun : guns) {
		gun->drawBullets();  //draws the bullets
	}
}

bool Player::checkCollision(Hitbox& x)
{
	if (hitbox == x)	//checks if the player is colliding with a given hitbox
	{
		getDamaged();
		return true;
	}if (checkInside(x)) {		//checks if the player is inside the hitbox or the hitbox inside the player
		getDamaged();
		return true;
	}
	return false;
}

Player::~Player() { //player deconstructor

}
void Player::changeWeapon(int w)
{
	switch (w)		//switches the weapons acording to the key pressed (1 to 4)
	{
	case 0:
		weaponInUse = laser;

		break;
	case 1:
		weaponInUse = mGun;

		break;
	case 2:
		weaponInUse = shotgun;
		break;
	}
}
void Player::update() {
	draw();  // displays the png
	for (auto gun : guns) { //updates the bullets location
		gun->moveBullets();
	}

}

void Player::animate(const float dirX)
{
	if (dirX > 0) {
		setShip(ships[1]); //changes the ship png
	}
	if (dirX < 0) {
		setShip(ships[2]); //changes the ship png
	}
	else {
		setShip(ships[0]); //changes the ship png
	}
}
