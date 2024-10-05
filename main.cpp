#include <raylib.h>

#include "game.hpp"

int main(void) {
    Game* game = new Game();

    game->init();

    game->initScreen();
    while (!WindowShouldClose()) {
        game->update();
        game->draw();
    }
    
    game->deinit();
}