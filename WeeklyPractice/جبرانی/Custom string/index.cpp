#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class CustomString
{
private:
    char *data;
    size_t length;

public:
    CustomString()
    {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }

    CustomString(const char *str)
    {
        if (str)
        {
            length = strlen(str);
            data = new char[length + 1];
            strcpy(data, str);
        }
        else
        {
            length = 0;
            data = new char[1];
            data[0] = '\0';
        }
    }

    CustomString(const CustomString &other)
    {
        length = other.length;
        data = new char[length + 1];
        strcpy(data, other.data);
    }

    CustomString &operator=(const CustomString &other)
    {
        if (this != &other)
        {
            delete[] data;
            length = other.length;
            data = new char[length + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    ~CustomString()
    {
        delete[] data;
    }

    CustomString operator+(const CustomString &other) const
    {
        char *temp = new char[length + other.length + 1];
        strcpy(temp, data);
        strcat(temp, other.data);
        CustomString result(temp);
        delete[] temp;
        return result;
    }

    CustomString substr(size_t pos, size_t len) const
    {
        if (pos >= length)
        {
            return CustomString("");
        }
        if (pos + len > length)
        {
            len = length - pos;
        }
        char *temp = new char[len + 1];
        strncpy(temp, data + pos, len);
        temp[len] = '\0';
        CustomString result(temp);
        delete[] temp;
        return result;
    }

    friend ostream &operator<<(ostream &os, const CustomString &obj)
    {
        os << obj.data;
        return os;
    }

    friend istream &operator>>(istream &is, CustomString &obj)
    {
        char buffer[1024];
        is >> buffer;
        delete[] obj.data;
        obj.length = strlen(buffer);
        obj.data = new char[obj.length + 1];
        strcpy(obj.data, buffer);
        return is;
    }
};

int main()
{
    CustomString s1("Hello ");
    CustomString s2("World");
    CustomString s3 = s1 + s2;
    cout << "Concatenation: " << s3 << endl;

    CustomString s4("Programming");
    CustomString sub = s4.substr(3, 5);
    cout << "Substr(3, 5): " << sub << endl;

    cout << "Enter a word: ";
    CustomString s5;
    cin >> s5;
    cout << "You entered: " << s5 << endl;

    return 0;
}