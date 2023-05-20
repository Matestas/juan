#include "MenuHandler.h"

MenuHandler::MenuHandler() {
    inMenu = false;
    currentHover = 0;
    inEndless = false;
    inHallOfFame = false;
    isFirstBoot = true;
    isRunning = true;
    inMainMenu = true;
    juanIsPlaying = false;
    bgmIsPlaying = false;
}

int MenuHandler::getCurrentHover() {
    return currentHover;
}
bool MenuHandler::backToMenu(ALLEGRO_EVENT& event)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            inEndless = false;
            inMenu = true;
            currentHover = 0;
            isFirstBoot = false;
            return true;
        }
   }
    return false;
}
void MenuHandler::test(MenuButton* menuButton, ALLEGRO_EVENT& event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_W) {
            al_draw_rectangle(100, 100, 200, 200, al_map_rgb(255, 255, 255), 3);
        }
    }
}
void MenuHandler::setCurrentHover(int currentHover)
{
    this->currentHover = currentHover;
}
void MenuHandler::changeMenuButton(std::vector <MenuButton*> menuButtons, ALLEGRO_EVENT& event) {
    if (event.type == ALLEGRO_EVENT_KEY_DOWN && currentHover < menuButtons.size()-1) {
        if (event.keyboard.keycode == ALLEGRO_KEY_S) {
            menuButtons[currentHover]->isHovered = false;
            menuButtons[currentHover + 1]->isHovered = true;
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
void MenuHandler::chooseMenuButton(MenuButton* menuButton, ALLEGRO_EVENT& event) {

    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_SPACE) {
            menuButton->isChoosen = true;
        }
    }

}
void MenuHandler::switchScreen(std::vector <MenuButton*> menuButtons) {
    for (int i = 0; i < menuButtons.size(); i++) {
        if (i == menuButtons.size() - 1 && menuButtons[i]->isChoosen == true) {   // Lets assume the exit button will be always the last in the vector
            inMainMenu = true;
            inMenu = false;
            menuButtons[i]->isHovered = false;
            menuButtons[i]->isChoosen = false;
        }

        else if (i == 0 && menuButtons[i]->isChoosen == true) {
            inMenu = false;
            
            inEndless = true;
            menuButtons[i]->isHovered = false;
            menuButtons[i]->isChoosen = false;
        }
    }



}


//Main Menu

void MainMenu::switchScreen(std::vector <MenuButton*> menuButtons, MenuHandler& menuHandler) {
    for (int i = 0; i < menuButtons.size(); i++) {
        if (i == menuButtons.size() - 1 && menuButtons[i]->isChoosen == true) {   // Lets assume the exit button will be always the last in the vector
            menuHandler.isRunning = false;
            menuButtons[i]->isHovered = false;
            menuButtons[i]->isChoosen = false;
        }
        else if (i == 1 && menuButtons[i]->isChoosen == true) {
            menuHandler.inHallOfFame = true;
            menuHandler.inMainMenu = false;
            menuButtons[i]->isHovered = false;
            menuButtons[i]->isChoosen = false;
        }
        else if (i == 0 && menuButtons[i]->isChoosen == true) {
            menuHandler.inEndless = true;
            menuHandler.inMainMenu = false;
            menuHandler.inMenu = false;
            menuButtons[i]->isHovered = false;
            menuButtons[i]->isChoosen = false;
        }
    }



}
bool MainMenu::backToMenu(ALLEGRO_EVENT& event, MenuHandler&menuhandler)
{
    if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
            menuhandler.inMenu = false;
            menuhandler.inEndless = false;
            menuhandler.inHallOfFame = false;
            menuhandler.inMainMenu = true;
            isFirstBoot = false;
            menuhandler.isFirstBoot = true;
            currentHover = 0;
            return true;
        }
    }
    return false;
}
bool MainMenu::restartGame() {
    if (!isFirstBoot) {
        return true;
    }
    else {
        return false;
    }
}
