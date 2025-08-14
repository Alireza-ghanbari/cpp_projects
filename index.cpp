#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter text: ";
    getline(cin, s);

    size_t pos = 0;
    while ((pos = s.find("is", pos)) != string::npos) {
        if (pos >= 2 && s.substr(pos - 2, 4) == "this") {
            pos += 2;
            continue;
        }
        s.replace(pos, 2, "this");
        pos += 4;
    }

    cout << "Result: " << s << endl;
    return 0;
}
