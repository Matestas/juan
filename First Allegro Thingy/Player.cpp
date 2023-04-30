
#include "Player.h"


Player::Player() : BaseEntity(0, 0) {
	speed = 20;
}

void Player::move(const float dirX, const float dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);
	if (x > 1180 || x < 0 || y < 0 || y > 620) {
		this->x -= (dirX * speed);
		this->y -= (dirY * speed);
	};

}


void  Player::setShipImage(ALLEGRO_BITMAP* image) {
	Ship = image;
}
// frame update
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 0, 0, 32, 32, x, y, 120, 120, 0);
	
}

Player::~Player() {

}
void Player::update() {
	draw();

}
