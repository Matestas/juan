#include <iostream>
#include "Collision.h"

bool Hitbox::operator==(Hitbox &t)
{
	// Check if the boxes are colliding along the x-axis
	bool x_colliding = (topLeftX <= t.bottomRightX) && (bottomRightX >= t.topLeftX);

	// Check if the boxes are colliding along the y-axis
	bool y_colliding = (topLeftY <= t.bottomRightY) && (bottomRightY >= t.topLeftY);

	// Return true if the boxes are colliding
	return (x_colliding && y_colliding);
}

void Hitbox::move(int xcoord, int ycoord) {
	this->topLeftX = xcoord;//moves hitbox
	this->topLeftY = ycoord;
    
	bottomRightX = xcoord + dimX;     
	bottomRightY = ycoord + dimY;
}

void Hitbox::draw()
{
	al_draw_rectangle(topLeftX, topLeftY, bottomRightX,bottomRightY, al_map_rgb(250, 25, 25), 2);//test function
}

Hitbox::Hitbox(int topLeftX, int dimX, int topLeftY, int dimY) //base Constructor
{
	
	this->bottomRightX = topLeftX+dimX;
	this->topLeftY = topLeftY;
	this->bottomRightY = topLeftY+dimY;
	this->topLeftX = topLeftX;
	this->dimX = dimX;
	this->dimY = dimY;
}

int Hitbox::getTopLeftX() {
	return topLeftX;
}
int Hitbox::getTopLeftY() {
	return topLeftY;
}
int Hitbox::getBottomRightX() {
	return bottomRightX;
}

int Hitbox::getBottomRightY() {
	return bottomRightY;
}
