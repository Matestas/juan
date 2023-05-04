
#include "Player.h"
#include "EventManager.h"
#include "assetLoader.h"

bool key_left= false;
bool key_right= false;
bool key_up= false;
bool key_down= false;


#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
typedef struct ALLEGRO_MOUSE_STATE ALLEGRO_MOUSE_STATE;

bool running;

int main() {
    
    // Initialize Allegro
    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    al_install_audio();
    al_init_acodec_addon();
    al_reserve_samples(1);
   
    //Create Objects
    Player player;
    
    Gun gun;
    MachineGun MGun;
    RocketLauncher RLauncher;
    Shotgun shotgun;
   

    //Create Display
    ALLEGRO_DISPLAY* display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    al_set_window_position(display, 250, 250);
    
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
    al_reserve_samples(5);
   
    ALLEGRO_SAMPLE* theme = load_sample("Shinji theme.mp3", "theme");
    al_play_sample(theme,0.3, 0, 1.5, ALLEGRO_PLAYMODE_LOOP, 0);
    //(&player.Ship, player.getBulletImage(0), player.getBulletSound(0), NULL, NULL, NULL);
    loadTest(player,gun,RLauncher,shotgun,MGun );
    while (running){
        al_wait_for_event(event_queue, &event);
        readmovementkeys(event);    // registers pressed keys and passes it to movePlayer
        check_PlayerShoot(event, player);  //checks if the mouse is pressed and makes the player shoot
        check_closeTab(event);
        
     
        if (al_get_timer_count(timer) > 0) {
            al_set_timer_count(timer, 0);
            if (al_is_event_queue_empty(event_queue)) {
                al_clear_to_color(al_map_rgb(0, 0, 0));
                player.update();             // updates the player sprite
                movePlayer(player);        // moves player according to pressed keys
                
                al_flip_display();
            }
        }
    }
    

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_bitmap(player.Ship);
    
    
    return 0;
}