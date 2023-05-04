
#include "Player.h"

Player::Player() : BaseEntity(0, 0), hitbox(0,dimX,0, dimY) {
	
	speed = 20;
	
	
}

void Player::move(const float dirX, const float dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);
	
	hitbox.move(x, y);
	if (!(map == hitbox)) {    
	
		this->x -= (dirX * speed);
		this->y -= (dirY * speed);
		hitbox.move(this->x, this->y);
	};

}

Collision Player::getHitBox()
{
	return hitbox;
}




void  Player::setShipImage(ALLEGRO_BITMAP* image) {
	Ship = image;
}
// frame update
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 0,10, 32, 22, x, y, 120, 83, 0);
	
}

Player::~Player() {

}
void Player::update() {
	draw();

}
