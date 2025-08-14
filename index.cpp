#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    ifstream inFile("input.txt");

    if (!inFile)
    {
        cerr << "error" << endl;
        return 1;
    }

    char ch;
    int i = 0, o = 0, u = 0, e = 0, a = 0;

    while (inFile.get(ch))
    {
        switch (tolower(ch))
        {
        case 'a':
            a++;
            break;
        case 'o':
            o++;
            break;
        case 'i':
            i++;
            break;
        case 'u':
            u++;
            break;
        case 'e':
            e++;
            break;
        }
    }

    cout << "a: " << a << endl;
    cout << "e: " << e << endl;
    cout << "i: " << i << endl;
    cout << "u: " << u << endl;
    cout << "o: " << a << endl;

    return 0;
}
