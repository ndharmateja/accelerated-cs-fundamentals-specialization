#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    Game g;

    cout << "Initial game state: " << endl;
    cout << g << endl;

    g.solve();

    cout << "Final game state: " << endl;
    cout << g << endl;

    return 0;
}
