#include <SDL2/SDL.h>
#include <iostream>
#include <game.hpp>

int main(int argc, char const *argv[])
{
    Game *game = new Game();
    bool isRunning = true;
    game->main(isRunning);
    SDL_Quit();
    return 0;
}

