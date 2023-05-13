
#pragma once
#include <allegro5/allegro.h>

#include "Player.h"
extern bool key_left;
extern bool key_right;
extern bool key_up;
extern bool key_down;
extern bool running;

void readmovementkeys(ALLEGRO_EVENT& event) {
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
void check_closeTab(ALLEGRO_EVENT& event) {

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        running = false;

    }
}
void movePlayer(Player& Player) {
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

void check_PlayerShoot(ALLEGRO_EVENT& event, Player& Player,int tick) {
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        Player.weapon->fire_bullet(Player.getX(), Player.getY(), tick);
    }
}
