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
class MenuButton
{
private:
	int dimX;
	int dimY;
	int x;
	int y;
	
	const char* text;

	ALLEGRO_FONT* font;
public:
	MenuButton(int x, int y, int dimX, int dimY, const char* text, ALLEGRO_FONT* font,bool isHovered = false);
	void draw();
	bool choose();
	bool isChoosen;
	bool isHovered;
	ALLEGRO_FONT* getFont();
};

