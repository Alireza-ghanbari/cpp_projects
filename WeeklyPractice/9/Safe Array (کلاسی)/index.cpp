#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

template <typename T>

class SafeArray
{
private:
    T *data;
    int size;

public:
    SafeArray(int n)
    {
        if (n <= 0)
        {
            throw invalid_argument("invalid size");
        }
        size = n;
        data = new T[size];
    }

    T &operator[](int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("out of range");
        }
        return data[index];
    }

    ~SafeArray()
    {
        delete[] data;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string type;
    cin >> type;

    try
    {
        int n;
        cin >> n;

        if (type == "int")
        {
            SafeArray<int> arr(n);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            int q;
            cin >> q;
            while (q--)
            {
                int idx;
                cin >> idx;
                try
                {
                    cout << arr[idx] << "\n";
                }
                catch (exception &e)
                {
                    cout << e.what() << "\n";
                }
            }
        }
        else if (type == "float")
        {
            SafeArray<float> arr(n);
            for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }

            int q;
            cin >> q;
            while (q--)
            {
                int idx;
                cin >> idx;
                try
                {
                    cout << arr[idx] << "\n";
                }
                catch (exception &e)
                {
                    cout << e.what() << "\n";
                }
            }
        }
    }
    catch (exception &e)
    {
        cout << e.what() << "\n";
    }

    return 0;
}
