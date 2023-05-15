#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
class Menu
{
private:
	int dimX;
	int dimY;
	int x;
	int y;
	
	const char* text;

	ALLEGRO_FONT* font;
public:
	Menu(int, int, int, int, const char*, ALLEGRO_FONT*);
	void draw();
	bool choose();
	bool isChoosen;
	bool isHovered;
	ALLEGRO_FONT* getFont();
};
