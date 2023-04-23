
#include "Player.h"
#include "EventManager.h"




bool key_left= false;
bool key_right= false;
bool key_up= false;
bool key_down= false;

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
typedef struct ALLEGRO_MOUSE_STATE ALLEGRO_MOUSE_STATE;
int delta;
bool running;

int main() {
    
    // Initialize Allegro
    al_init();
    al_init_font_addon();
    al_init_image_addon();
    al_init_primitives_addon();
    al_install_keyboard();
    al_install_mouse();
    
    //Create Objects
    
    Player Player;

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
    running = true;     // loop variable to keep the window running
    ALLEGRO_EVENT event;  // create event that can be modified

    

    while (running) {
        
       
                                           
        al_wait_for_event(event_queue, &event);
        al_clear_to_color(al_map_rgb(0, 0, 0));
        Player.update();             // updates the player sprite
        check_closeTab(event);      
        readmovementkeys(event);    // registers pressed keys and passes it to movePlayer
        check_PlayerShoot(event,Player);  //checks if the mouse is pressed and makes the player shoot
        movePlayer(Player);        // moves player according to pressed keys
        
        moveall(Player.getbullets());  // bullets
        
        update(Player.getbullets());
        al_flip_display();
                     
    }

    al_destroy_font(font);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
   
    
    return 0;
}