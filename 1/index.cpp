#include <iostream>

using namespace std;

int main()
{
    int n, i;
    long s = 0;
    cout << "Enter a positive integer number: ";
    cin >> n;
    for (i = 1; i <= n; i++)
        s += i;
    cout << s;
    return 0;
}
