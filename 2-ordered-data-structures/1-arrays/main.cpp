#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int values[5] = {2, 3, 5, 7, 11};
    cout << "values[3]: " << values[3] << endl;

    cout << "size of int: " << sizeof(int) << endl;
    int offset = (long)(values + 2) - (long)values;
    cout << "offset (bytes) between 0 and 2: " << offset << endl;

    return 0;
}
