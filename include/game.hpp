#pragma once
#include <player.hpp>
#include <window.hpp>
#include <SDL2/SDL.h>
#include <string>

class Game
{
private:
    Window *window;
    Player *player;
    int highScore;
    int currScore;
    int foodX, foodY;
    

public:
    Game();
    ~Game();
    void main(bool &isRunning);
    void restart();
    // void updateHighScore(int score);
};
