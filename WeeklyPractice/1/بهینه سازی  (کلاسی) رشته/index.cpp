#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;
    getline(cin, line);

    string result = "";
    int count = 0;
    bool inWord = false;

    for (int i = 0; i < line.length(); i++)
    {
        char c = line[i];

        if (c != ' ')
        {
            result += c;

            if (!inWord)
            {
                count++;
                inWord = true;
            }
        }
        else
        {
            if (inWord)
            {
                result += ' ';
                inWord = false;
            }
        }
    }
    cout << result << endl;
    cout << "Number of words: " << count << endl;

    return 0;
}