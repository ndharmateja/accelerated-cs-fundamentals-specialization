#include "Game.h"

Game::Game()
{
    for (int i = 0; i < 3; i++)
    {
        Stack stack;
        stacks_.push_back(stack);
    }

    Cube blue(4, uiuc::HSLAPixel::BLUE);
    Cube orange(3, uiuc::HSLAPixel::ORANGE);
    Cube yellow(2, uiuc::HSLAPixel::YELLOW);
    Cube purple(1, uiuc::HSLAPixel::PURPLE);

    stacks_[0].push_back(blue);
    stacks_[0].push_back(orange);
    stacks_[0].push_back(yellow);
    stacks_[0].push_back(purple);
}

std::ostream &operator<<(std::ostream &os, const Game &game)
{
    for (int i = 0; i < 3; i++)
    {
        os << "Stack[" << i << "]: " << game.stacks_[i] << std::endl;
    }
    return os;
}

void Game::solve()
{
    // TODO
}