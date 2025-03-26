#include <iostream>
#include "Stack.h"

std::ostream &operator<<(std::ostream &os, const Stack &stack)
{
    for (int i = 0; i < stack.size(); i++)
    {
        const Cube &cube = stack.cubes_.at(i);
        os << cube.getLength() << " ";
    }
    return os;
}

void Stack::push_back(const Cube &cube)
{
    cubes_.push_back(cube);
}

Cube Stack::removeTop()
{
    Cube cube = cubes_.back();
    cubes_.pop_back();
    return cube;
}

Cube &Stack::peekTop()
{
    return cubes_.back();
}

unsigned Stack::size() const
{
    return cubes_.size();
}