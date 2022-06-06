#include <game.hpp>
#include <iostream>
#include <SDL2/SDL.h>

#define WIDTH 1000
#define HEIGHT 700

Game::Game()
{
    window = new Window(WIDTH, HEIGHT);
    player = new Player(window);
    // window->draw();
}

Game::~Game()
{
    SDL_Quit();
}
void Game::restart()
{
    window->clear();
    SDL_Delay(20);
}

void Game::main(bool &isRunning)
{
    SDL_Event event;

    int foodX, foodY;
    foodX = rand() % window->getCols() * window->getPixels();
    foodY = rand() % window->getRows() * window->getPixels();

    window->addFoodRect(foodX, foodY);
    window->draw();
    while (SDL_PollEvent(&event) || isRunning)
    {

        Moves outcome;

        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_r:
                std::cout << "restart" << std::endl;
                restart();
                break;
            case SDLK_q:
                std::cout << "quit" << std::endl;
                isRunning = false;
                break;
            case SDLK_UP:
                outcome = player->move(up, foodX, foodY);
                break;
            case SDLK_DOWN:
                outcome = player->move(down, foodX, foodY);
                break;
            case SDLK_LEFT:
                outcome = player->move(left, foodX, foodY);
                break;
            case SDLK_RIGHT:
                outcome = player->move(right, foodX, foodY);
                break;
            default:
                break;
            }
        }
        else
        {
            outcome = player->move(player->getCurrentDirection(), foodX, foodY);
        }
        if (outcome == death)
        {
            std::cout << "dead" << std::endl;
            isRunning = false;
        }
        else if (outcome == eat)
        {
            foodX = rand() % window->getCols() * window->getPixels();
            foodY = rand() % window->getRows() * window->getPixels();
        }
        SDL_Delay(50);
    }
}
