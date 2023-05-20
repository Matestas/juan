#include "Loader.h"

ALLEGRO_BITMAP* Loader::load_image(const char* filename, const char* image_ID) {//loads images
	ALLEGRO_BITMAP* image = al_load_bitmap(filename);

	if (!image) { //gives error message
		std::cerr << "Failed to load " << image_ID << std::endl;

	}
	return image;

}

ALLEGRO_SAMPLE* Loader::load_sample(const char* filename, const char* sample_ID) { //loads sound
	ALLEGRO_SAMPLE* sound = al_load_sample(filename);

	if (!sound) { //gives error mesage
		std::cerr << "Failed to load " << sample_ID << std::endl;

	}
	return sound;
}