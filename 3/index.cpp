#include <iostream>

using namespace std;

int vfunct(int);
void rfunct(int &);

int main()
{
    int x = 5, y = 10;
    cout << x << endl
         << vfunct(x) << endl
         << x << endl;
    cout << y << endl;
    rfunct(y);
    cout << y << endl;
    return 0;
}

int vfunct(int a)
{
    return a *= a;
}
void rfunct(int &b)
{
    b *= b;
}