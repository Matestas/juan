#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>

#include <vector>

class BaseEntity {

protected:
	int x = 0;
	int y = 0;
	int speed;
	void draw();
	
public:
	BaseEntity() {
		speed = 0;
	}
	BaseEntity(int x, int y) {
		setX(x);
		setY(y);
		
	}
	void setX(int x) {
		this->x = x;

	}
	void setY(int y) {
		this->y = y;

	}
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	void move(const int dirX, const int dirY){}
	
};


