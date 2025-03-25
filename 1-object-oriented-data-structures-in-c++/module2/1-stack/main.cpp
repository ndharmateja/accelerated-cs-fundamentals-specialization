#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    int x = 5;
    cout << " x: " << x << endl;
    cout << "&x: " << &x << endl;

    int y = 7;
    cout << " y: " << y << endl;
    cout << "&y: " << &y << endl;

    int z = 7;
    cout << " z: " << z << endl;
    cout << "&z: " << &z << endl;

    return 0;
}
