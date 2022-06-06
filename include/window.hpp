#pragma once
#include <SDL2/SDL.h>
#include <tuple>

enum Color
{
    green,
    red,
    black
};

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int width, height, rows, cols;
    const int pixels = 10;

public:
    Window(int width, int height);
    ~Window();
    void addRect(int x, int y, Color color);
    void addFoodRect(int x, int y);
    void addPlayerRect(int x, int y);
    void clear();
    void draw();
    int getWidth() { return width; };
    int getHeight() { return height; };
    int getPixels() { return pixels; };
    int getRows() { return rows; };
    int getCols() { return cols; };

    // static std::tuple<int, int> getXY(int coord);
    // static int getCoord(int x, int y);
};
