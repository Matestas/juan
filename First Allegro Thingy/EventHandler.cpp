#include "EventHandler.h"

#include <allegro5/allegro.h>

#include "Player.h"
extern bool key_left;
extern bool key_right;
extern bool key_up;
extern bool key_down;



void EventHandler::readMovementKeys(ALLEGRO_EVENT& event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        switch (event.keyboard.keycode) { //reads movement keys
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
void EventHandler::checkCloseTab(ALLEGRO_EVENT& event, MenuHandler & menuHandler) {

    if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { //checks if the window was closed
        menuHandler.isRunning = false;

    }
}
void EventHandler::movePlayer(Player& Player) { //moves the player accordind to the key
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

void EventHandler::resetKeys() //resets the keys
{
    key_down = false;
    key_left = false;
    key_right = false;
    key_up = false;
}

void EventHandler::readWeaponChangeKeys(ALLEGRO_EVENT& event,Player& player)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {//changes the wepon acording to the key
        switch (event.keyboard.keycode) {
        case ALLEGRO_KEY_1:
            player.changeWeapon(0);
            break;
        case ALLEGRO_KEY_2:
            player.changeWeapon(1);
            break;
        case ALLEGRO_KEY_3:
            player.changeWeapon(2);
            break;
 
        }
    }

}

EventHandler::EventHandler(): isRunning(true)
{
    
}

void EventHandler::checkPlayerShoot(ALLEGRO_EVENT& event, Player& Player, Ticker tick) {
    if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        Player.weaponInUse->fire_bullet(Player.getX(), Player.getY(), tick);
    }
}

