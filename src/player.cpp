#include <player.hpp>
#include <tuple>
#include <iostream>

Player::Player(Window *window)
{
    body.push_back(std::tuple<int, int>{100, 100});
    body.push_back(std::tuple<int, int>{50, 100});
    this->window = window;
    currDirection = right;
}

void Player::grow()
{
}

Moves Player::checkMove(int x, int y, int foodX, int foodY)
{
    if ((x == foodX) && (y == foodY))
    {
        std::cout << "eat" << std::endl;
        return eat;
    }
    else if ((x < 0) || (y < 0) || x > window->getWidth() || y > window->getHeight())
    {
        std::cout << "collided" << std::endl;
        return death;
    }
    else
    {
        return normal;
    }
}

// TODO invalid moves
Moves Player::move(Direction direction, int foodX, int foodY)
{
    window->clear();
    window->addFoodRect(foodX, foodY);

    Direction prev = currDirection;
    currDirection = direction;

    std::tuple<int, int> anchor = body.front();
    int x_anchor = std::get<0>(anchor);
    int y_anchor = std::get<1>(anchor);

    int pixels = window->getPixels();

    Moves outcome;

    if (direction == left /* && (prev == up || prev == down) */)
    {
        outcome = checkMove(x_anchor - pixels, y_anchor, foodX, foodY);
    }
    else if (direction == right /* && (prev == up || prev == down) */)
    {
        outcome = checkMove(x_anchor + pixels, y_anchor, foodX, foodY);
    }
    else if (direction == up /* && (prev == right || prev == left) */)
    {
        outcome = checkMove(x_anchor, y_anchor - pixels, foodX, foodY);
    }
    else if (direction == down /* && (prev == right || prev == left) */)
    {
        outcome = checkMove(x_anchor, y_anchor + pixels, foodX, foodY);
    }

    if (outcome == death)
    {
        return death;
    }
    else
    {
        int x_new, y_new;
        switch (direction)
        {
        case right:
            x_new = x_anchor + pixels;
            y_new = y_anchor;
            break;
        case left:
            x_new = x_anchor - pixels;
            y_new = y_anchor;
            break;
        case up:
            x_new = x_anchor;
            y_new = y_anchor - pixels;
            break;
        case down:
            x_new = x_anchor;
            y_new = y_anchor + pixels;
            break;
        default:
            break;
        }
        if (outcome != eat)
        {
            body.pop_back();
        }
        body.insert(body.begin(), std::tuple<int, int>{x_new, y_new});
    }

    for (auto &i : body)
    {
        int x = std::get<0>(i);
        int y = std::get<1>(i);

        window->addPlayerRect(x, y);
    }

    window->draw();

    return outcome;
}

Direction Player::getCurrentDirection()
{
    return currDirection;
}