#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int *x;
    int sz = 3;
    x = new int[sz];

    for (int i = 0; i < sz; i++)
    {
        x[i] = i * i + 7;
    }

    cout << "[" << x[0] << ", " << x[1] << ", " << x[2] << "]" << endl;

    // Delete array memory
    // and assign null pointer
    delete[] x;
    x = nullptr;

    return 0;
}
