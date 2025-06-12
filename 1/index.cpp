#include <iostream>

using namespace std;

int main()
{
    int count, n;
    float x, sum = 0, avg;
    cout << "Enter number of scores: ";
    cin >> n;
    cout << "Enter " << n << " float number:" << endl;
    while (count < n)
    {
        cin >> x;
        sum += x;
        count++;
    }
    avg = sum / n;
    cout << "Average of these " << n << " number is: " << avg << endl;
    return 0;
}
