
#include "Player.h"


Player::Player() : BaseEntity(0, 0) {

	speed = 20;
}
void Player::fire_bullet() {
	
}
void Player::move(const int dirX, const int dirY) {
	this->x += (dirX * speed);
	this->y += (dirY * speed);
	if (x > 1180 || x < 0 || y < 0 || y > 620) {
		this->x -= (dirX * speed);
		this->y -= (dirY * speed);
	};
	
}
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 0, 0, 1083, 1063, x, y, 100, 100, 0);
	
}
Player::~Player() {

}
void Player::update() {
	draw();

}
std::vector<Bullet>& Player::getbullets() {
	return bullets;
}