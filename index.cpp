#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    string text;
    cout << "Enter text: ";
    getline(cin, text);

    int wordCount = 0, sentenceCount = 0;
    bool inWord = false;

    for(char ch : text){
        if(isspace(ch)){
            if(inWord){
                wordCount++;
                inWord = false;
            }
        }else if(isalpha(ch)){
            inWord = true;
        }

        if(ch == '.' || ch == '?' || ch == '!'){
            sentenceCount++;
        }
    }

    if(inWord) wordCount++;

    cout << "Word count: " << wordCount << endl;
    cout << "sentence count: " << sentenceCount << endl;

    return 0;
}
