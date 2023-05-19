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
#include <string>
#include <cstring>

class Score
{
private:
	ALLEGRO_FONT* font;
public:
	Score(ALLEGRO_FONT* font);
	int score;
	double difficultyRatio;
	void addScore(int points);
	void display();
	void changeDifficulty();
};

