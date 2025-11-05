#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
private:
    int hour;
    int minute;
    int second;

public:
    Time()
    {
        hour = 0;
        minute = 0;
        second = 0;
    }

    Time(int h, int m, int s)
    {
        setTime(h, m, s);
    }

    void setTime(int h, int m, int s)
    {
        hour = (h >= 0 && h < 24) ? h : 0;
        minute = (m >= 0 && m < 60) ? m : 0;
        second = (s >= 0 && s < 60) ? s : 0;
    }

    void display() const
    {
        cout << setfill('0') << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second;
    }

    void increment()
    {
        this->second++;

        if (this->second >= 60)
        {
            this->second = 0;
            this->minute++;
        }

        if (this->minute >= 60)
        {
            this->minute = 0;
            this->hour++;
        }

        if (this->hour >= 24)
        {
            this->hour = 0;
        }
    }

    friend bool isEqual(const Time &t1, const Time &t2);
};

bool isEqual(const Time &t1, const Time &t2)
{
    return (t1.hour == t2.hour &&
            t1.minute == t2.minute &&
            t1.second == t2.second);
}

int main()
{
    int h, m, s;
    cin >> h >> m >> s;

    Time t1(h, m, s);
    Time t2(12, 59, 59);
    cout << "Initial time: ";
    t1.display();
    cout << endl;

    t1.increment();

    cout << "After increment: ";
    t1.display();
    cout << endl;

    cout << "Times are equal: " << (isEqual(t1, t2) ? "true" : "false") << endl;

    return 0;
}
