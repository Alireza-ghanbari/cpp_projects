#include <iostream>

using namespace std;

int pascal(int n, int k)
{
    if (k == 0 || k == n)
        return 1;
    return pascal(n - 1, k - 1) + pascal(n - 1, k);
}

int main()
{
    int rows = 7;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << pascal(i, j) << " ";
        }
        cout << endl;
    }

    return 0;
}
