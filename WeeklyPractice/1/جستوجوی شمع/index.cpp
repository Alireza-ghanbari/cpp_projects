#include <bits/stdc++.h>
using namespace std;

struct Coord
{
    int row;
    int col;
};

Coord coord_outer_in_topright(int n, long long m)
{
    if (n == 1)
        return {1, 1};
    int k = 0;
    long long mloc = m;
    while (true)
    {
        int side = n - 2 * k;
        if (side == 1)
        {
            return {1 + k, 1 + k};
        }
        int P = 4 * (side - 1);
        if (mloc <= P)
        {
            int s = side;
            int t = (int)(mloc - 1);
            if (t <= s - 2)
            {
                int r = 1 + k + t;
                int c = n - k;
                return {r, c};
            }
            t -= (s - 1);
            if (t <= s - 2)
            {
                int r = n - k;
                int c = n - k - t;
                return {r, c};
            }
            t -= (s - 1);
            if (t <= s - 2)
            {
                int r = n - k - t;
                int c = 1 + k;
                return {r, c};
            }
            t -= (s - 1);
            {
                int r = 1 + k;
                int c = 1 + k + t;
                return {r, c};
            }
        }
        else
        {
            mloc -= P;
            k++;
        }
    }
}

Coord final_coord(int n, long long m)
{
    Coord p = coord_outer_in_topright(n, m);
    Coord q;
    q.row = p.col;
    q.col = p.row;
    return q;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long s, d;
    cin >> n >> s >> d;

    Coord ps = final_coord(n, s);
    Coord pd = final_coord(n, d);

    int rs = ps.row, cs = ps.col;
    int rd = pd.row, cd = pd.col;

    int dx = cd - cs;
    int dy = rd - rs;

    if (dx != 0)
    {
        if (dx < 0)
            cout << -dx << " L\n";
        else
            cout << dx << " R\n";
    }
    if (dy != 0)
    {
        if (dy < 0)
            cout << -dy << " U\n";
        else
            cout << dy << " D\n";
    }

    return 0;
}
