#include <iostream>

using namespace std;

void fswap(float &, float &);

int main()
{
    float a = 5.2, b = 4.3;
    cout << a << " - " << b;
    fswap(a, b);
    cout << endl;
    cout << a << " - " << b;
    return 0;
}

void fswap(float &x, float &y)
{
    float t;
    t = x;
    x = y;
    y = t;
}