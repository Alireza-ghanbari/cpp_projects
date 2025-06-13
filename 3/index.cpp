#include <iostream>

using namespace std;

char lowToUp(char c1)
{
    char c2;
    c2 = (c1 >= 'a' && c1 <= 'z') ? ('A' + c1 - 'a') : c2;
    return (c2);
}

int main()
{
    char x;
    x = cin.get();
    cout << lowToUp(x);
    return 0;
}