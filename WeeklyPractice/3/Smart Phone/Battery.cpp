#include "Battery.h"
#include <iostream>

using namespace std;

Battery::Battery(int capacity, double level)
    : capacitymAh(capacity), levelPercent(level) {}

void Battery::drain(double percent)
{
    levelPercent -= percent;
    cout << "Battery drain: " << percent << "%" << endl;
    if (levelPercent < 0)
        levelPercent = 0;
}

void Battery::charge(double percent)
{
    levelPercent += percent;
    cout << "Battery charge: " << percent << "%" << endl;;
    if (levelPercent > 100)
        levelPercent = 100;
}

double Battery::getLevel() const
{
    return levelPercent;
}

void Battery::showInfo() const
{
    cout << "Battery: " << capacitymAh << " mAh, Level: "
         << levelPercent << "%" << endl;
}
