#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
    string name;
    int id;
    double gpa;

    bool operator<(const Student &other) const
    {
        if (gpa == other.gpa)
            return id < other.id;
        return gpa < other.gpa;
    }

    friend istream &operator>>(istream &in, Student &s)
    {
        in >> s.name >> s.id >> s.gpa;
        return in;
    }

    friend ostream &operator<<(ostream &out, const Student &s)
    {
        out << s.name << " " << s.id << " " << s.gpa;
        return out;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Student> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (auto &s : a)
        cout << s << "\n";

    return 0;
}
