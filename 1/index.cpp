#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    while (1)
    {
        count ++;
        if(count >= 5)
        break;
    }
    cout << "counter: " << count << endl;
    return 0;
}
