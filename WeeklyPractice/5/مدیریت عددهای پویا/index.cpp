#include <iostream>
#include <iomanip>

using namespace std;

class NumberArray
{
    int *data;
    int size;

public:
    NumberArray(int s)
    {
        size = (s > 0) ? s : 0;
        data = new int[size];
        for (int i = 0; i < size; i++)
            data[i] = 0;
    }

    ~NumberArray()
    {
        delete[] data;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
            this->data[index] = value;
    }

    double average() const
    {
        if (size == 0)
            return 0;
        double sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return sum / size;
    }

    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i];
            if (i < size - 1)
                cout << " ";
        }
        cout << endl;
    }

    friend bool hasHigherAverage(const NumberArray &a, const NumberArray &b);
};

bool hasHigherAverage(const NumberArray &a, const NumberArray &b)
{
    return a.average() > b.average();
}

int main()
{
    int n1;
    cin >> n1;
    NumberArray arr1(n1);
    for (int i = 0; i < n1; i++)
    {
        int value;
        cin >> value;
        arr1.setValue(i, value);
    }

    int n2;
    cin >> n2;
    NumberArray arr2(n2);
    for (int i = 0; i < n2; i++)
    {
        int value;
        cin >> value;
        arr2.setValue(i, value);
    }

    cout << "Array 1: ";
    arr1.display();
    cout << "Average: " << fixed << setprecision(0) << arr1.average() << endl;

    cout << "Array 2: ";
    arr2.display();
    cout << "Average: " << fixed << setprecision(0) << arr2.average() << endl;

    if (hasHigherAverage(arr1, arr2))
        cout << "First array has higher average." << endl;
    else if (hasHigherAverage(arr2, arr1))
        cout << "Second array has higher average." << endl;
    else
        cout << "Both arrays have the same average." << endl;

    return 0;
}
