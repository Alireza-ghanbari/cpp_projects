#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    ifstream inFile("input.txt");
    ofstream outFile("result.txt");

    if (!inFile)
    {
        cerr << "error" << endl;
        return 1;
    }

    int count[26] = {};
    char ch;

    while (inFile.get(ch))
    {
        if (isalpha(ch))
        {
            ch = tolower(ch);
            count[ch - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] != 0)
        {
            outFile << char('a' + i) << ": " << count[i] << endl;
        }
    }

    inFile.close();
    outFile.close();

    cout << "result.txt updated" << endl;

    return 0;
}
