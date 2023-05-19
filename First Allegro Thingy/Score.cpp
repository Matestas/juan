#include "Score.h"


Score::Score(ALLEGRO_FONT *font):difficultyRatio(1), font(font)
{
	score = 0;
}


void Score::addScore(int points)
{
	score += points;
	
	// need to pass score to const char*
}

void Score::display()
{
	std::string strNumber = std::to_string(score);
	const char* charNumber = strNumber.c_str();
	al_draw_text(font, al_map_rgb(50, 250, 250), 500, 30, ALLEGRO_ALIGN_CENTER, charNumber);
}

void Score::changeDifficulty()
{
	if (score % 250 == 0 && difficultyRatio <= 2) {
		difficultyRatio += 0.05;
	}
	else if (score % 500 == 0 && difficultyRatio <= 2.5) {
		difficultyRatio += 0.04;
	}
	else if (score % 750 == 0 && difficultyRatio <= 3.25) {
		difficultyRatio += 0.03;
	}
	else if (score % 1000 == 0 && difficultyRatio > 3.25) {
		difficultyRatio += 0.01;
	}
}
