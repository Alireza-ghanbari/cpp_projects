#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, c;
    cout << "Enter three real number: " << endl;
    cin >> a >> b >> c;
    if ((a < c + b) && (b < a + c) && (c < a + b))
        cout << "It is a triangle";
    else
        cout << "Not a triangle";
    return 0;
}
