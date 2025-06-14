#include <iostream>

using namespace std;

void reverse(void);

int main()
{
    reverse();
    return 0;
}

void reverse(void)
{
    char c;
    if ((c = cin.get()) != '\n')
        reverse();
    cout << c;
    return;
}