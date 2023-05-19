#include "Score.h"


Score::Score(ALLEGRO_FONT *font): score(0), difficultyRatio(1), font(font)
{
}

void Score::addScore(int points)
{
	score += points;
	// need to pass score to const char*
}

void Score::display()
{
	
	al_draw_text(font, al_map_rgb(150, 150, 150), 0, 70, 0, str_score);
}

void Score::changeDifficulty()
{
	if (score % 500 == 0 && difficultyRatio <= 2) {
		difficultyRatio += 0.05;
	}
	else if (score % 1000 == 0 && difficultyRatio <= 2.5) {
		difficultyRatio += 0.04;
	}
	else if (score % 1500 == 0 && difficultyRatio <= 3.25) {
		difficultyRatio += 0.03;
	}
	else if (score % 1000 == 0 && difficultyRatio > 3.25) {
		difficultyRatio += 0.01;
	}
}
