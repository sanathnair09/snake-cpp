#pragma once
#include <tuple>
#include <vector>
#include <window.hpp>

enum Direction
{
    up,
    down,
    left,
    right
};

enum Moves
{
    normal,
    eat,
    death,
};

class Player
{
private:
    void grow();
    Moves checkMove(int x, int y, int foodX, int foodY);
    // Direction prevDirection;
    Direction currDirection;

    std::vector<std::tuple<int, int>> body;
    Window * window;

public:
    Moves move(Direction direction, int foodX, int foodY);
    Player(Window *Window);
    ~Player();
    Direction getCurrentDirection();
};