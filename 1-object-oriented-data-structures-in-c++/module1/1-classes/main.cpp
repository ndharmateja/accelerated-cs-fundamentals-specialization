#include <iostream>
#include "Cube.h"

int main(int argc, char const *argv[])
{
    Cube c;
    c.setLength(3.48);
    std::cout << "Cube {" << std::endl
              << "    length: "
              << c.getLength() << std::endl
              << "    surface area: "
              << c.getSurfaceArea() << std::endl
              << "    volume: "
              << c.getVolume() << std::endl
              << "}" << std::endl;
    return 0;
}
