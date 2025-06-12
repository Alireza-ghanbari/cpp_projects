#include <iostream>

using namespace std;

int main()
{
    unsigned int n;
    cout << "Enter a number: ";
    cin >> n;
    switch (n)
    {
    case 0:
        cout << "It is 0";
        break;
    case 1:
        cout << "It is 1";
        break;
    case 2:
        cout << "It is 2";
        break;
    default:
        cout << "default" << endl;
    }
    return 0;
}
