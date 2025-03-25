#include <iostream>
#include "Cube.h"

using namespace std;

// This is problematic code
// as the cube object is being created in stack
// and once this function stops executing, the object
// is removed from the stack memory
Cube *createCubeProblematic(int length)
{
    Cube cube;
    cube.setLength(length);
    return &cube;
}

int main()
{
    Cube *cube_ptr = createCubeProblematic(3.8);
    cout << "Cube {" << endl
         << "    length: "
         << cube_ptr->getLength() << endl
         << "    surface area: "
         << cube_ptr->getSurfaceArea() << endl
         << "    volume: "
         << cube_ptr->getVolume() << endl
         << "}" << endl;
}