
#include "Player.h"
#include "EventManager.h"
#include "assetLoader.h"
#include "Enemy.h"
#include "Mover.h"
#include "Collision.h"
#include "Ticker.h"
#include "laser.h"
#include "Menu.h"
#include "MenuHandler.h"
#include "EventHandler.h"
#include "Score.h"
#include <cmath>

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

    MenuHandler menuHandler;
    MainMenu mainMenu;
    std::vector <Enemy*> currentEnemies;
    bool isLoading = true;

   
    
    //Create Display
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_position(display, 0, 0);
    
    // Create font,timer and queue of events
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(0.01666);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    //Create Score object now since it needed the font to load
    Score score(font);
    
    //Register possible events
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_mouse_event_source());
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_hide_mouse_cursor(display);
    al_start_timer(timer);

    //runtime variables
    handler.isRunning = true;     // loop variable to keep the window running
    ALLEGRO_EVENT event;  // create event that can be modified
    
	int sw = 0;
	int cycles = 0;
    
    //Initialize Random
	srand((unsigned)time(NULL));
   
    //Reserve Sample Capacity
    al_reserve_samples(5);
    
    //Load Assets
    ALLEGRO_SAMPLE* theme = load_sample("Shinji theme.mp3", "theme");
    ALLEGRO_SAMPLE* juan = load_sample("juan.mp3", "juantheme");
    vector <ALLEGRO_SAMPLE*> soundtrack;
    soundtrack.push_back(theme);
    soundtrack.push_back(juan);
    ALLEGRO_SAMPLE_ID BGMid;
    ALLEGRO_SAMPLE_ID juanId;
    vector <ALLEGRO_SAMPLE_ID> soundIDs;
    soundIDs.push_back(BGMid);
    soundIDs.push_back(juanId);

    //al_play_sample(theme, 0.1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &BGMid);
    ALLEGRO_FONT* menuFont = al_load_font("Freedom-10eM.ttf", 50, 0);
    //(&player.Ship, player.getBulletImage(0), player.getBulletSound(0), NULL, NULL, NULL);
    loadTest(player);
    MenuButton* play = new MenuButton(490,50, 200, 50, "Play", menuFont);
    MenuButton* hallOfFame = new MenuButton(490, 125, 200, 50, "Hall of Fame", menuFont);
    MenuButton* exit = new MenuButton(490, 200, 200, 50, "Exit", menuFont);
    MenuButton* resume = new MenuButton(490, 50, 200, 50, "Resume", menuFont);
    MenuButton* backToMenu = new MenuButton(490, 200, 200, 50, "Menu", menuFont);
    std::vector <MenuButton*> mainMenuButtons;
    std::vector <MenuButton*> menuButtons;
    mainMenuButtons.push_back(play);
    mainMenuButtons.push_back(hallOfFame);
    mainMenuButtons.push_back(exit);
    menuButtons.push_back(resume);
    menuButtons.push_back(backToMenu);


    while (menuHandler.isRunning){       // Main Menu
        //std::cout << "bottom: (" << player.getHitbox().getBottomRightX() << "," << player.getHitbox().getBottomRightY() << " Top: (" << player.getHitbox().getTopLeftX() << ", " << player.getHitbox().getTopLeftY() << ") " << std::endl;
        
        if (menuHandler.inMainMenu) {

            al_wait_for_event(event_queue, &event);
            if (mainMenu.getCurrentHover() == 0) {
                play->isHovered = true;
            }
            handler.checkCloseTab(event, menuHandler);
            mainMenu.changeMenuButton(mainMenuButtons, event);
            mainMenu.chooseMenuButton(mainMenuButtons[mainMenu.getCurrentHover()], event);
            mainMenu.switchScreen(mainMenuButtons, menuHandler);
            if (al_get_timer_count(timer) > 0) {
                al_set_timer_count(timer, 0);
                if (al_is_event_queue_empty(event_queue)) {
                    al_clear_to_color(al_map_rgb(20, 20, 20));
                    play->draw();
                    hallOfFame->draw();
                    exit->draw();
                }
            }
        }

        else if (menuHandler.inMenu) {          // Menu
            al_wait_for_event(event_queue, &event);
            if (menuHandler.getCurrentHover() == 0) {
                resume->isHovered = true;
            }
            menuHandler.changeMenuButton(menuButtons, event);
            handler.checkCloseTab(event, menuHandler);
            menuHandler.chooseMenuButton(menuButtons[menuHandler.getCurrentHover()], event);
            menuHandler.switchScreen(menuButtons);
            
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));

                        if (!menuHandler.isFirstBoot) {
                            player.update();
                            for (int i = 0; i < currentEnemies.size(); i++) {
                                currentEnemies[i]->draw();
                            }

                        }
                        resume->draw();
                        backToMenu->draw();

                    }
                }
        }
            else if (menuHandler.inHallOfFame) {
                al_wait_for_event(event_queue, &event);
                handler.checkCloseTab(event, menuHandler);
                mainMenu.backToMenu(event, menuHandler);
                 
                
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));
                        al_draw_circle(600, 300, 50, al_map_rgb(22, 52, 90), 5);
                    }
                }
                
            


            }
            else if(menuHandler.inEndless) {
                
                al_wait_for_event(event_queue, &event);
                
                handler.readMovementKeys(event);    // registers pressed keys and passes it to movePlayer
                handler.checkPlayerShoot(event, player, gunTicker);  //checks if the mouse is pressed and makes the player shoot
                handler.checkCloseTab(event, menuHandler);
                menuHandler.backToMenu(event);
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));
                        //score.display();
                        player.update(); // updates the player sprite           
                        movePlayer(player);        // moves player according to pressed keys
                        universalTicker.ticker();
                        universalTicker.checkTick();    
                        gunTicker.ticker();
                        if (universalTicker.getTick() == 16) {
                            cycles += 1;

                        if (cycles == 1) {
                            
                            int enemy_spawn_count = ((rand() % (int) round(score.difficultyRatio)*2) + 1);
                           
                            for (int i = 0; i < enemy_spawn_count; i++) {
                                Enemy* newenemy = new Enemy(1250, rand() % 700, score.difficultyRatio * 4, score.difficultyRatio * 4);
                                currentEnemies.push_back(newenemy);

                            }
                            cycles = 0;
                        }

                        }
                        
                        for (int i = 0; i < currentEnemies.size(); i++) {
                            currentEnemies[i]->draw();
                            move.randomMover(*currentEnemies[i],universalTicker);
                            currentEnemies[i]->move(currentEnemies[i]->dx, currentEnemies[i]->dy);
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