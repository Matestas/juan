
#include "Player.h"

Player::Player(int dimX,int dimY) : BaseEntity(0, 0, dimX, dimY){
	
	speedX = 20;
	speedY = 20;
	this->dimX = dimX;
	this->dimY = dimY;
}




void  Player::setShipImage(ALLEGRO_BITMAP* image) {
	Ship = image;
}
// frame update
void Player::draw() {
	
	al_draw_scaled_bitmap(Ship, 3,11, 27, 9, x, y, dimX, dimY, 0);
	al_draw_rectangle(x, y, x + dimX, y + dimY, al_map_rgb(250, 250, 25), 2);
}

Player::~Player() {

}
void Player::update() {
	draw();

}
