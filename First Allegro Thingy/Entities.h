#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>
#include <cstdlib>
#include "Map.h"



class BaseEntity {

protected:
	int x = 0;
	int y = 0;
	int speed;
	void draw();

	Map map;
	
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
	
	
};


