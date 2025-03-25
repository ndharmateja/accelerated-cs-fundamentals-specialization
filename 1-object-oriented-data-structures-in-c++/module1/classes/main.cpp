#include <iostream>
#include "Cube.h"

int main(int argc, char const *argv[])
{
    Cube c;
    c.setLength(5.5);
    std::cout << "Cube{length: "
              << c.getLength()
              << ", surface area: "
              << c.getSurfaceArea()
              << ", volume: "
              << c.getVolume()
              << "}" << std::endl;
    return 0;
}
