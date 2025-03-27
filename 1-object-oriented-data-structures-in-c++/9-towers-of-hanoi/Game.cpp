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

void Game::move(int from, int to, int temp, int numBlocks)
{
    if (numBlocks == 0)
        return;

    // Move n-1 blocks from 'from' to 'temp' using 'to' as temp
    move(from, temp, to, numBlocks - 1);
    // Move 1 block from 'from' to 'to' using 'temp' as temp
    this->stacks_[to].push_back(this->stacks_[from].removeTop());
    // Move the n-1 blocks from 'temp' to 'to' using 'from' as temp
    move(temp, to, from, numBlocks - 1);
}

void Game::solve()
{
    move(0, 2, 1, 4);
}