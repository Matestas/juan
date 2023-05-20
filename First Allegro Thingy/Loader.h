#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <iostream>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <vector>


class Loader
{
public:
	Loader():loadedAssetCount(0) {};

	ALLEGRO_BITMAP* load_image(const char* filename, const char* image_ID);
	ALLEGRO_SAMPLE* load_sample(const char* filename, const char* sample_ID);
private:
	int loadedAssetCount;
};

