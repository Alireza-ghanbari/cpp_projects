#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long x)
{
    if (x < 0)
        return false;
    long long r = (long long)sqrt(x);
    return r * r == x || (r + 1) * (r + 1) == x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    long long sum = 0;
    int score = 0;

    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
        {
            sum += a[top][j];
            if (isPerfectSquare(sum))
                score++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            sum += a[i][right];
            if (isPerfectSquare(sum))
                score++;
        }
        right--;
        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
            {
                sum += a[bottom][j];
                if (isPerfectSquare(sum))
                    score++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                sum += a[i][left];
                if (isPerfectSquare(sum))
                    score++;
            }
            left++;
        }
    }

    cout << "\n"
         << score << "\n";
    return 0;
}
