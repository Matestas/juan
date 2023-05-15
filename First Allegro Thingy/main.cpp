
#include "Player.h"
#include "EventManager.h"
#include "assetLoader.h"
#include "Enemy.h"
#include "Mover.h"
#include "Collision.h"
#include "Ticker.h"
#include "laser.h"
#include "Menu.h"
#include "EventHandler.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;

bool key_left= false;
bool key_right= false;
bool key_up= false;
bool key_down= false;




typedef struct ALLEGRO_MOUSE_STATE ALLEGRO_MOUSE_STATE;

bool running;

int main(){

    // Initialize Allegro
    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    
    //Create Objects
    Map map;
    Player player;
    Mover move;
    
    Enemy enemyTest;
    Ticker universalTicker;
    Ticker gunTicker;
    EventHandler handler;
    std::vector <Enemy*> currentEnemies;
    bool isLoading = true;

   
    
    //Create Display
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_position(display, 0, 0);
    
    // Create font,timer and queue of events
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(0.01666);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    
    //Register possible events
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_hide_mouse_cursor(display);
    al_start_timer(timer);

    //runtime variables
    running = true;     // loop variable to keep the window running
    ALLEGRO_EVENT event;  // create event that can be modified
	int sw = 0;
	int cycles = 0;
    
    //Initialize Random
	srand((unsigned)time(NULL));
   
    //Reserve Sample Capacity
    al_reserve_samples(5);
    
    //Load Assets
    ALLEGRO_SAMPLE* theme = load_sample("Shinji theme.mp3", "theme");
    ALLEGRO_FONT* menuFont = al_load_font("Freedom-10eM.ttf", 24, 0);
    al_play_sample(theme,0.3, 0, 1.5, ALLEGRO_PLAYMODE_LOOP, 0);
    //(&player.Ship, player.getBulletImage(0), player.getBulletSound(0), NULL, NULL, NULL);
    loadTest(player);
    Menu* resume = new Menu(490, 100, 300, 100, "Resume", menuFont);
    Menu* exit = new Menu(490, 300, 300, 100, "Exit", menuFont);
    std::vector <Menu*> menuButtons;
    menuButtons.push_back(resume);
    menuButtons.push_back(exit);


    while (running){
        //std::cout << "bottom: (" << player.getHitbox().getBottomRightX() << "," << player.getHitbox().getBottomRightY() << " Top: (" << player.getHitbox().getTopLeftX() << ", " << player.getHitbox().getTopLeftY() << ") " << std::endl;
        
     

            if (handler.inMenu) {
                al_wait_for_event(event_queue, &event);
                handler.changeMenuButton(menuButtons, event);
                handler.checkCloseTab(event);
                handler.chooseMenuButton(menuButtons[handler.getCurrentHover()], event);
                handler.switchScreen(menuButtons);
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));

                        handler.changeMenuButton(menuButtons, event);
                        handler.chooseMenuButton(menuButtons[handler.getCurrentHover()], event);
                        handler.switchScreen(menuButtons);
                        resume->draw();
                        exit->draw();

                    }
                }
            }
            else {
                al_wait_for_event(event_queue, &event);
                handler.readMovementKeys(event);    // registers pressed keys and passes it to movePlayer
                handler.checkPlayerShoot(event, player, gunTicker);  //checks if the mouse is pressed and makes the player shoot
                handler.checkCloseTab(event);
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));
                        player.update(); // updates the player sprite           
                        movePlayer(player);        // moves player according to pressed keys
                        universalTicker.ticker();
                        universalTicker.checkTick();
                        gunTicker.ticker();
                        if (universalTicker.getTick() == 16) {
                            cycles += 1;

                        if (cycles == 1) {
                            int enemy_spawn_count = rand() % 5 + 5;
                            for (int i = 0; i < enemy_spawn_count; i++) {
                                Enemy* newenemy = new Enemy(1250, rand() % 700, 5 + rand() % 2, 5 + rand() % 2);
                                currentEnemies.push_back(newenemy);

                            }
                            cycles = 0;
                        }

                        }
                        for (int i = 0; i < currentEnemies.size(); i++) {
                            currentEnemies[i]->draw();
                            currentEnemies[i]->move(move.randomMover(universalTicker) - 3, move.randomMover(universalTicker));
                        }
                        if (universalTicker.getTick() == 128) {

                            player.changeWeapon(sw);
                            sw++;
                            sw &= 3;
                        }

                        for (auto it = currentEnemies.begin(); it != currentEnemies.end(); ++it) {
                            Enemy* enemy = *it;
                            player.checkBullets(enemy->getHitbox());
                            if (player.weaponInUse->bullets->checkhit(enemy->getHitbox())) {
                                currentEnemies.erase(it);
                                delete enemy; // delete the enemy object
                                break; // stop the loop after erasing one enemy
                            }
                        }



                }
            }
                }
        al_flip_display();
    }
			
        
    

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(player.Ship);
    
    
    return 0;
}