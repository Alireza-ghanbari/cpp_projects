#include <iostream>

using namespace std;

void modify(int[]);

int main()
{
    int a[5];
    for (int i = 0; i < 5; i++)
        a[i] = i + 1;
    modify(a);
    for (int i = 0; i < 5; i++)
        cout << a[i] << endl;
    return 0;
}

void modify(int a[])
{
    for (int i = 0; i < 5; i++)
        a[i] += 2;
}