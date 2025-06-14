#include <iostream>

using namespace std;

long int factorial(int);

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Factorial = " << factorial(n) << endl;
    return 0;
}

long int factorial(int n)
{
    if (n <= 1)
        return (1);
    else
        return (n * factorial(n - 1));
}