#include "EventHandler.h"
#include <allegro5/allegro.h>

#include "Player.h"
extern bool key_left;
extern bool key_right;
extern bool key_up;
extern bool key_down;

int EventHandler::getCurrentHover() {
    return currentHover;
}
void EventHandler::backToMenu(ALLEGRO_EVENT event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            inMenu = true;
            inEndless = false;

        }
    }
}
void EventHandler::test(Menu* menuButton, ALLEGRO_EVENT& event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W) {
            al_draw_rectangle(100, 100, 200, 200, al_map_rgb(255, 255, 255), 3);
        }
    }
}
void EventHandler::changeMenuButton(std::vector <Menu*> menuButtons,ALLEGRO_EVENT&event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN && currentHover < menuButtons.size()){
        if (event.keyboard.keycode == ALLEGRO_KEY_S) {
            menuButtons[currentHover]->isHovered = false;
            menuButtons[currentHover+1]->isHovered = true;
            currentHover += 1;
        }
        
    }
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W && currentHover > 0) {
            menuButtons[currentHover]->isHovered = false;
            menuButtons[currentHover - 1]->isHovered = true;
            currentHover -= 1;
        }
        
    }
   
}
void EventHandler::chooseMenuButton(Menu* menuButton, ALLEGRO_EVENT& event) {

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
            menuButton->isChoosen = true;
        }
    }

}
void EventHandler::switchScreen(std::vector <Menu*> menuButtons) {
    for (int i = 0; i < menuButtons.size(); i++) {
        if (i == menuButtons.size()-1 && menuButtons[i]->isChoosen == true) {   // Lets assume the exit button will be always the last in the vector
            isRunning = false;
            menuButtons[i]->isChoosen = false;
        }
        
        else if (i == 0 && menuButtons[i]->isChoosen == true) {
            inMenu = false;
            inEndless = true;
            menuButtons[i]->isChoosen = false;
        }
    }
    
    
    
}

void EventHandler::readMovementKeys(ALLEGRO_EVENT& event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_A:
            key_left = true;
            break;
        case ALLEGRO_KEY_D:
            key_right = true;
            break;
        case ALLEGRO_KEY_W:
            key_up = true;
            break;
        case ALLEGRO_KEY_S:
            key_down = true;
            break;
        }
    }
    if (event.type == ALLEGRO_EVENT_KEY_UP) {
        switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_A:
            key_left = false;
            break;
        case ALLEGRO_KEY_D:
            key_right = false;
            break;
        case ALLEGRO_KEY_W:
            key_up = false;
            break;
        case ALLEGRO_KEY_S:
            key_down = false;
            break;
        }
    }
};
void EventHandler::checkCloseTab(ALLEGRO_EVENT& event) {

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        isRunning = false;

    }
}
void EventHandler::movePlayer(Player& Player) {
    if (key_left && key_up) {
        Player.move(-0.7071, -0.7071);
    }
    else if (key_left && key_down) {
        Player.move(-0.7071, 0.7071);
    }
    else if (key_right && key_down) {
        Player.move(0.7071, 0.7071);
    }
    else if (key_right && key_up) {
        Player.move(0.7071, -0.7071);
    }
    else if (key_left) {
        Player.move(-1, 0);

    }
    else if (key_right) {
        Player.move(1, 0);

    }
    else if (key_up) {
        Player.move(0, -1);

    }
    else if (key_down) {
        Player.move(0, 1);

    }

}

EventHandler::EventHandler(bool inMenu, int currentHover): inMenu(inMenu), currentHover(currentHover),inEndless(false)
{
    
}

void EventHandler::checkPlayerShoot(ALLEGRO_EVENT& event, Player& Player, Ticker tick) {
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        Player.weaponInUse->fire_bullet(Player.getX(), Player.getY(), tick);
    }
}

void EventHandler::changeMusic(std::vector <ALLEGRO_SAMPLE*> soundtrack, std::vector <ALLEGRO_SAMPLE_ID> soundIDs){
    if (inMenu) {
        if (juanIsPlaying && !isFirstBoot) {
            al_stop_sample(&soundIDs[1]);
            juanIsPlaying = false;
            
        }
        if (!bgmIsPlaying) {
            al_play_sample(soundtrack[0], 0.1, 0, 1.5, ALLEGRO_PLAYMODE_LOOP, &soundIDs[0]);
            bgmIsPlaying = true;
        }
    }
    if (inEndless) {
        if (!juanIsPlaying) {
            
            al_play_sample(soundtrack[1], 0.1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &soundIDs[1]);
            juanIsPlaying = true;
        }
        if (bgmIsPlaying) {
            al_stop_sample(&soundIDs[0]);
            bgmIsPlaying = false;
        }
    }
}