#include <iostream>
#include "Collision.h"

bool Hitbox::operator==(Hitbox &t)
{
	bool x_colliding = (topLeftX <= t.bottomRightX) && (bottomRightX >= t.topLeftX);

	// Check if the boxes are colliding along the y-axis
	bool y_colliding = (topLeftY <= t.bottomRightY) && (bottomRightY >= t.topLeftY);

	// Return true if the boxes are colliding in both axes
	return (x_colliding && y_colliding);
}

void Hitbox::move(int xcoord, int ycoord) {
	this->topLeftX = xcoord;
	this->topLeftY = ycoord;
    
	bottomRightX = xcoord + dimX;     
	bottomRightY = ycoord + dimY;
}

Hitbox::Hitbox(int topLeftX, int dimX, int topLeftY, int dimY)
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
