#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i + 1 < n; i += 2)
    {
        swap(s[i], s[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        s[i] = 'a' + ('z' - s[i]);
    }

    cout << s << "\n";
    return 0;
}
