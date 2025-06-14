#include <iostream>

using namespace std;

void printarr(int[][3]);

int main()
{
    int arr1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arr2[2][3] = {1, 2, 3, 4, 5};
    int arr3[2][3] = {{1, 2}, {4}};
    printarr(arr1);
    cout << endl;
    printarr(arr2);
    cout << endl;
    printarr(arr3);
    return 0;
}

void printarr(int a[][3])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
}