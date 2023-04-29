
#ifndef LOADERS_H
#define LOADERS_H


	ALLEGRO_BITMAP* load_image(const char* filename, const char* image_ID);
	ALLEGRO_SAMPLE* load_sample(const char* filename, const char* sample_ID);


	ALLEGRO_BITMAP* load_image(const char* filename, const char* image_ID) {
		ALLEGRO_BITMAP* image = al_load_bitmap(filename);

		if (!image) {
			std::cerr << "Failed to load " << image_ID << std::endl;

		}
		return image;
	}

	ALLEGRO_SAMPLE* load_sample(const char* filename, const char* sample_ID) {
		ALLEGRO_SAMPLE* sound = al_load_sample(filename);

		if (!sound) {
			std::cerr << "Failed to load " << sample_ID << std::endl;

		}
		return sound;
	}


#endif
 