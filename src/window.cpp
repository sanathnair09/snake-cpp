#include <window.hpp>
#include <SDL2/SDL.h>
#include <iostream>
#include <tuple>

Window::~Window()
{
    SDL_DestroyWindow(window);
    // delete window;
}

Window::Window(int width, int height)
{
    this->width = width;
    this->height = height;
    this->rows = height / pixels;
    this->cols = width / pixels;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL Init failed" << std::endl;
    }
    else
    {
        std::cout << "SDL Init success" << std::endl;
        window = SDL_CreateWindow("window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_METAL);
        if (window == NULL)
        {
            std::cout << "window creation failed" << std::endl;
        }
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    }
    clear();
    std::cout << "window done" << std::endl;
}

void Window::addFoodRect(int x, int y)
{
    addRect(x, y, red);
}

void Window::addPlayerRect(int x, int y)
{
    addRect(x, y, green);
}

void Window::addRect(int x, int y, Color color)
{
    int r, g, b;
    switch (color)
    {
    case green:
        r = 0;
        g = 255;
        b = 0;
        break;
    case red:
        r = 255;
        g = 0;
        b = 0;
        break;
    case black:
        r = 0;
        g = 0;
        b = 0;
        break;
    default:
        break;
    }
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = pixels;
    rect.h = pixels;

    // clear();
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Window::draw()
{
    SDL_RenderPresent(renderer);
}

void Window::clear()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    // SDL_RenderPresent(renderer);
}

// std::tuple<int, int> Window::getXY(int coord)
// {
// }

// int Window::getCoord(int x, int y)
// {
//     return x * 3 + y + 1;
// }