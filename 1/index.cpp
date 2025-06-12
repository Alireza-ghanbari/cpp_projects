#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n, i;
    long fact = 1;
    cout << "Enter a positive integer number: ";
    cin >> n;
    for (i = 1; i <= n; i++)
        fact *= i;
    cout << fact << endl;
    return 0;
}
