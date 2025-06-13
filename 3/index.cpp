#include <iostream>

using namespace std;

long int factorial(int n)
{
    long int prod = 1;
    if (n > 1)
        for (int i = 2; i <= n; i++)
            prod *= i;
    return (prod);
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}