#include "Score.h"


Score::Score(ALLEGRO_FONT *font):difficultyRatio(1), font(font)
{
	score = 0;  // initializing the score
}


void Score::addScore(int points)
{
	score += points;
}

void Score::display()
{
	std::string strNumber = std::to_string(score);		//converts the int to string 
	const char* charNumber = strNumber.c_str();
	al_draw_text(font, al_map_rgb(50, 250, 250), 500, 30, ALLEGRO_ALIGN_CENTER, charNumber); // displays the score
}

void Score::changeDifficulty()
{
	if (score % 50 == 0 && difficultyRatio <= 2) {				//changes the dificulty ratio acording to the score
		difficultyRatio += 0.05;
	}
	else if (score % 200 == 0 && difficultyRatio <= 2.5) {
		difficultyRatio += 0.04;
	}
	else if (score % 250 == 0 && difficultyRatio <= 3.25) {
		difficultyRatio += 0.03;
	}
	else if (score % 500 == 0 && difficultyRatio > 3.25) {
		difficultyRatio += 0.01;
	}
}
