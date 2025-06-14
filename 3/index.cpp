#include <iostream>

using namespace std;

long int fib(int);

int main()
{
    int n;
    cout << "Enter an integer value: ";
    cin >> n;
    cout << "fibonacci = " << fib(n) << endl;
    return 0;
}

long int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return (fib(n - 1) + fib(n - 2));
}