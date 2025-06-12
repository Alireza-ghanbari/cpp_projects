#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    float x[3][4], total = 0;
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            cin >> x[i][j];

    for (i = 0; i < 3; i++)
        for (j = 0; j < 4; j++)
            total += x[i][j];

    cout << "Total = " << total << endl;
    return 0;
}