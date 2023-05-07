#include <iostream>
#include "Collision.h"

bool Hitbox::operator==(Hitbox &t)
{
	if (topLeftX < t.bottomRightX) return false;   // rect1 is to the left of rect2
	if (bottomRightX > t.topLeftX) return false;   // rect1 is to the right of rect2
    if (topLeftY < t.bottomRightY) return false;   // rect1 is above rect2
	if (bottomRightY > t.topLeftY) return false; 
	return true;
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
