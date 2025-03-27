#include <iostream>
#include "Cube.h"

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    uiuc::Cube c;
    c.setLength(2.4);
    cout << "Cube {" << endl
         << "    length: "
         << c.getLength() << endl
         << "    surface area: "
         << c.getSurfaceArea() << endl
         << "    volume: "
         << c.getVolume() << endl
         << "}" << endl;
    return 0;
}