#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s;
    getline(cin, s); 

    int i = 0, j = (int)s.size() - 1;
    while (i < j)
    {
        while (i < j && !isalnum(s[i]))
            i++;
        while (i < j && !isalnum(s[j]))
            j--;

        if (i < j)
        {
            if (tolower(s[i]) != tolower(s[j]))
            {
                cout << "false\n";
                return 0;
            }
            i++;
            j--;
        }
    }

    cout << "true\n";
    return 0;
}
