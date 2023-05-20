
#include "Player.h"
#include"HallOfFame.h"

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
#include "Loader.h"
#include <string>
#include <cstring>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

using namespace std;

bool key_left= false;
bool key_right= false;
bool key_up= false;
bool key_down= false;

void resetGame(MenuHandler &menuHandler,Player &df,Player &nw,vector<Enemy*> &enemies,Score &score,EventHandler &handler) {
    menuHandler.inMainMenu = true;
    menuHandler.inEndless = false;
    handler.resetKeys();

    nw.resetPlayer(df);
    enemies.clear();

    score.score = 0;
    
}


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
    
    //Create Example Objects or single objects
    Loader loader;
    Map map;
    Player playerEx;
    
    Mover move;

    Enemy enemyEx;
    Ticker universalTicker;
    Ticker gunTicker;
    EventHandler handler;
    MenuHandler menuHandler;
    MainMenu mainMenu;
    HallOfFame halloffame;
    std::vector <Enemy*> currentEnemies;

    bool isLoading = true;

   
    
    //Create Display
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_position(display, 0, 0);
    
    // Create default font,timer and queue of events
    ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_TIMER* timer = al_create_timer(0.01666);
    ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
    ALLEGRO_FONT* numberFont = al_load_font("SuPostcode-VGeLe.ttf", 50, 0);
    //Create Score object now since it needed the font to load
    Score score(numberFont);
    
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
    //Read Hall of Fame
    halloffame.readFile();
    ////Load Assets

    // Load Ship Variations
    std::vector < ALLEGRO_BITMAP* > playerShips;
    ALLEGRO_BITMAP* normalShip = loader.load_image("Main_Ship.png", "MS");
    ALLEGRO_BITMAP* acceleratingShip = loader.load_image("mainShipAcelerated.png", "MSA");
    ALLEGRO_BITMAP* breakingShip = loader.load_image("MainShipBackwards.png", "MSB");
    playerShips.push_back(normalShip);
    playerShips.push_back(acceleratingShip);
    playerShips.push_back(breakingShip);
    playerEx.setPlayerImages(playerShips);
    playerEx.setShip(playerShips[0]);
    ALLEGRO_BITMAP* onHitExplosion = loader.load_image("OnHitExplosion.png", "HitExplosion");

    for (auto gun : playerEx.guns) {
        gun->setExplosion(onHitExplosion);
        gun->loadBullets();
    }
    
    
    
    //Load Soundtrack
    ALLEGRO_SAMPLE* juan = loader.load_sample("juan.mp3", "juan");
    vector <ALLEGRO_SAMPLE*> soundtrack;
    soundtrack.push_back(juan);
    ALLEGRO_SAMPLE_ID BGMid;
    vector <ALLEGRO_SAMPLE_ID> soundIDs;        // used to stop tracks
    soundIDs.push_back(BGMid);

    

    //Load Enemy Ship
    
    enemyEx.setTotalExplosion(loader.load_image("Explosion.png", "Explosion"));
    enemyEx.setEnemyShip(loader.load_image("EnemyShip.png", "EnemyShipImage"));
    
    //Load Gun Sounds
    playerEx.guns[0]->setGunSound(loader.load_sample("MachineGunSound1Shot.wav", "MachineGunSound"));                                             //MRSL
    //playerEx.guns[1]->setGunSound(loader.load_sample("juanito.mp3", "RocketLauncherSound"));
    playerEx.guns[2]->setGunSound(loader.load_sample("ShotGunSound.wav", "ShotGunSound"));
    playerEx.guns[3]->setGunSound(loader.load_sample("LaserSound.wav", "LazerSound"));


    //Create multiple objects
    Player player(playerEx);

    //Load aditional fonts
    
    ALLEGRO_FONT* menuFont = al_load_font("Freedom-10eM.ttf", 50, 0);
    
    ALLEGRO_FONT* HallofFameFont = al_load_font("Freedom-10eM.ttf", 70, 0);
    //(&player.Ship, player.getBulletImage(0), player.getBulletSound(0), NULL, NULL, NULL);
    //Load Menu
    MenuButton* play = new MenuButton(490,50, 243, 150, loader.load_image("PlayButton.png", "PlayB"));
    MenuButton* hallOfFame = new MenuButton(490, 300, 243, 150, loader.load_image("HallofFameButton.png", "HallB"));
    MenuButton* exit = new MenuButton(490,550, 243, 150, loader.load_image("ExitButton.png", "ExitB"));
    MenuButton* resume = new MenuButton(490, 50, 243, 150, loader.load_image("ResumeButton.png", "ResumeB"));
    MenuButton* backToMenu = new MenuButton(490, 250, 243, 150, loader.load_image("menuButton.png", "menuB"));
    std::vector <MenuButton*> mainMenuButtons;
    std::vector <MenuButton*> menuButtons;
    mainMenuButtons.push_back(play);
    mainMenuButtons.push_back(hallOfFame);
    mainMenuButtons.push_back(exit);
    menuButtons.push_back(resume);
    menuButtons.push_back(backToMenu);

    //Play BGM
    al_play_sample(juan, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, &BGMid);

    while (menuHandler.isRunning){       // Main Menu
        if (menuHandler.inMainMenu == true) {
            resetGame(menuHandler, playerEx, player, currentEnemies, score, handler);
        }
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
                            player.draw();
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
                        al_draw_rectangle(240, 40,1040, 125, al_map_rgb(192, 26, 26), 5);
                        al_draw_text(numberFont, al_map_rgb(224, 168, 63), 460, 200 , ALLEGRO_ALIGN_CENTER, "1");
                        al_draw_text(numberFont, al_map_rgb(156, 149, 143), 460, 280, ALLEGRO_ALIGN_CENTER, "2");
                        al_draw_text(numberFont, al_map_rgb(163, 96, 57), 460, 360, ALLEGRO_ALIGN_CENTER, "3");
                        al_draw_text(numberFont, al_map_rgb(60, 50, 40), 460, 440, ALLEGRO_ALIGN_CENTER, "4");
                        al_draw_text(numberFont, al_map_rgb(60, 50, 40), 460, 520, ALLEGRO_ALIGN_CENTER, "5");
                        al_draw_text(menuFont, al_map_rgb(224, 168, 63), 520, 203, ALLEGRO_ALIGN_CENTER, "st");
                        al_draw_text(menuFont, al_map_rgb(156, 149, 143), 520, 283, ALLEGRO_ALIGN_CENTER, "nd");
                        al_draw_text(menuFont, al_map_rgb(163, 96, 57), 520, 363, ALLEGRO_ALIGN_CENTER, "rd");
                        al_draw_text(menuFont, al_map_rgb(60, 50, 40), 520, 443, ALLEGRO_ALIGN_CENTER, "th");
                        al_draw_text(menuFont, al_map_rgb(60, 50, 40), 520, 523, ALLEGRO_ALIGN_CENTER, "th");
                        al_draw_text(HallofFameFont, al_map_rgb(192,26,26), 640, 50, ALLEGRO_ALIGN_CENTER, "HALL OF FAME");
                        for (int i = 0; i < halloffame.getScores().size() && i < 5; i++) {
                            ALLEGRO_COLOR color= al_map_rgb(60, 50, 40);
                            if(i == 0) {
                                color = al_map_rgb(224, 168, 63);
                            }
                            if (i == 1) {
                                color = al_map_rgb(156, 149, 143);
                            }
                            if (i == 2) {
                                color = al_map_rgb(163, 96, 57);
                            }
                           
                            
                            std::string strScore = std::to_string(halloffame.getScores()[i]);		//converts the int to string 
                            const char *charScore = strScore.c_str();
                            al_draw_text(numberFont, color, 640, 200+ i * 80, ALLEGRO_ALIGN_CENTER, charScore);
                            
                        }
                    }
                }
                
            


            }
            else if(menuHandler.inEndless) {
                
                al_wait_for_event(event_queue, &event);
                
                handler.readMovementKeys(event);    // registers pressed keys and passes it to movePlayer
                handler.checkPlayerShoot(event, player, gunTicker);  //checks if the mouse is pressed and makes the player shoot
                handler.checkCloseTab(event, menuHandler);
                handler.readWeaponChangeKeys(event, player);
                menuHandler.backToMenu(event);
                score.display();
                if (al_get_timer_count(timer) > 0) {
                    al_set_timer_count(timer, 0);
                    if (al_is_event_queue_empty(event_queue)) {
                        al_clear_to_color(al_map_rgb(20, 20, 20));
                        score.display();          
                        handler.movePlayer(player);        // moves player according to pressed keys
                        universalTicker.ticker();
                        universalTicker.checkTick();    
                        gunTicker.ticker();
                        player.update();
                        
                       
                        
                        for (auto it = currentEnemies.begin(); it != currentEnemies.end() ;) {
                            Enemy* enemyt = *it;
                            if (player.checkCollision(*enemyt->getHitbox())) {
                                delete enemyt; // Delete the enemy object
                                it = currentEnemies.erase(it); // Erase and get the iterator to the next element
                                score.addScore(10);
                            }
                            else {
                                if (player.checkGunHit(*enemyt->getHitbox())) {
                                    player.checkBullets(*enemyt->getHitbox());
                                    //delete enemyt; // Delete the enemy object
                                    
                                    if (enemyt->getDamaged(player.weaponInUse->getDamage())) {      // 
                                        it = currentEnemies.erase(it); // Erase and get the iterator to the next element
                                        score.addScore(10);
                                    }
                                    
                                }
                                else {
                                    if (enemyt->getHitbox()->getBottomRightX() <= 70) {
                                        delete enemyt; // Delete the enemy object
                                        it = currentEnemies.erase(it); // Erase and get the iterator to the next element
                                        player.getDamaged();
                                    }
                                    else {
                                        ++it;
                                    }
                                }
                            }
                        }
                        if (universalTicker.getTick() == 16) {
                            cycles += 1;

                        if (cycles == 1) {
                            
                            int enemy_spawn_count = ((rand() % (int) round(score.difficultyRatio)*2) + 1);
                           
                            for (int i = 0; i < enemy_spawn_count; i++) {
                                Enemy* newenemy = new Enemy(1250, rand() % 700, score.difficultyRatio * 4, score.difficultyRatio * 4, std::time(nullptr) % 3 + 1);
                                newenemy->setEnemyShip(enemyEx.getEnemyImage());
                                currentEnemies.push_back(newenemy);
                                if ((score.score % 250 == 0)&&score.score!=0) {
                                    for (int e = 0; e < 6*score.difficultyRatio; e++) {
                                        Enemy* newenemy = new Enemy(1250, rand() % 700, score.difficultyRatio * 4, score.difficultyRatio * 4, std::time(nullptr) % 3 + 1, 30, 30,10);
                                        newenemy->setEnemyShip(enemyEx.getEnemyImage());
                                        
                                        currentEnemies.push_back(newenemy);
                                    }
                                    
                                }
                            }
                            cycles = 0;
                        }

                        }
                        
                        for (int i = 0; i < currentEnemies.size(); i++) {
                            currentEnemies[i]->draw();
                            move.toMove(*currentEnemies[i], universalTicker);
                           
                            currentEnemies[i]->move(currentEnemies[i]->dx, currentEnemies[i]->dy);                          
                        }

                        if (player.health <= 0) {
                            halloffame.addHScore(score.score);
                            halloffame.writeFile();
                            resetGame(menuHandler, playerEx, player, currentEnemies, score,handler);
                            
                        }
                        
                        for (auto gun : player.guns)
                            for (int i = 0; i < 30; i++) {
                                gun->bullets[i].explode();
                        };                       
                }

            }
        }
        al_flip_display();
    }
			
        
    

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    
    
    
    
    return 0;
}