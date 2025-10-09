#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int freq[26] = {0};

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    for (int i = 0; i < (int)s.size(); i++)
    {
        if (freq[s[i] - 'a'] == 1)
        {
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}
