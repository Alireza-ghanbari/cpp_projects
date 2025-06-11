#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x, s;
    cout << "Enter x: ";
    cin >> x;
    if (x < 0)
        cout << "x is negative" << endl;
    else
    {
        s = sqrt(x);
        cout << "sqrt of x is: " << s << endl;
    }

    return 0;
}
