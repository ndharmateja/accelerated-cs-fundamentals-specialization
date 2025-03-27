#include <iostream>
#include "Cube.h"

using namespace std;

// This is not problematic as the object is created
// using new keyword => created on heap
// Delete the allocated with "delete" keyword
Cube *createCube(double length)
{
    Cube *cube_ptr = new Cube;
    cube_ptr->setLength(length);
    return cube_ptr;
}

int main()
{
    Cube *cube_ptr = createCube(3.8);
    cout << "Cube {" << endl
         << "    length: "
         << cube_ptr->getLength() << endl
         << "    surface area: "
         << cube_ptr->getSurfaceArea() << endl
         << "    volume: "
         << cube_ptr->getVolume() << endl
         << "}" << endl;

    // Assign null pointer to the pointer so that
    // it won't point to the deleted heap memory anymore
    delete cube_ptr;
    cube_ptr = nullptr;
}