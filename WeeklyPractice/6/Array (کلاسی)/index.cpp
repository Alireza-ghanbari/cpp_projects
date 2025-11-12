#include <iostream>

using namespace std;

class Array
{
private:
    int size;
    int *data;

public:
    Array()
    {
        size = 0;
        data = nullptr;
    }

    Array(int s)
    {
        size = s;
        data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[size] = 0;
        }
    }

    Array(const Array &other)
    {
        size = other.size;
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            data = nullptr;
        }
    }

    ~Array()
    {
        delete[] data;
    }

    Array &operator=(const Array &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;

        size = other.size;
        if (size > 0)
        {
            data = new int[size];
            for (int i = 0; i < size; i++)
            {
                data[i] = other.data[i];
            }
        }
        else
        {
            data = nullptr;
        }
        return *this;
    }

    Array operator+(const Array &other)
    {
        if (size != other.size)
        {
            cout << "Size of arrays must be equal" << endl;
            return Array();
        }

        Array result(size);
        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    int &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range!" << endl;
            exit(1);
        }
        return data[index];
    }

    const int &operator[](int index) const
    {
        if (index < 0 || index >= size)
        {
            cout << "Index out of range!" << endl;
            exit(1);
        }
        return data[index];
    }

    friend istream &operator>>(istream &in, Array &arr)
    {
        cout << "Enter " << arr.size << " elements --> ";
        for (int i = 0; i < arr.size; i++)
        {
            in >> arr.data[i];
        }
        return in;
    }

    friend ostream &operator<<(ostream &out,const Array &arr)
    {
        out << "[ ";
        for (int i = 0; i < arr.size; i++)
        {
            out << arr.data[i] << " ";
        }
        out << "]";
        return out;
    }

};

int main(){
    Array a(3), b(3);
    cout << "Fill array a: " << endl;
    cin >> a;
    cout << "Fill array b: " << endl;
    cin >> b;

    cout << "A[]: " << a << endl;
    cout << "B[]: " << b << endl;

    Array c = a + b;
    cout << "Result (a + b): " << c << endl;

    c[0] = 55;
    cout << "Test after c[0] = 55 : " << c << endl;

    Array d = c;
    cout << "d is Copy of c: " << d << endl;

    return 0;
}