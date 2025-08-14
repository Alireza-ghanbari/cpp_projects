#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    char str [201];
    cout << "Enter text: ";
    cin.getline(str, 201);

    string s = str;

    size_t pos = 0;
    while((pos = s.find("IS", pos)) != string::npos){
        s.replace(pos, 2, "WHERE"),
        pos += 5;
    }

    cout << "Resault: " << s << endl;

    return 0;
}
