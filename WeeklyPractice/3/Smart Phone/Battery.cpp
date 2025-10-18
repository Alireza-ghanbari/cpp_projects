#include "Battery.h"
#include <iostream>

using namespace std;

Battery::Battery(int capacity, double level)
    : capacitymAh(capacity), levelPercent(level) {}

double Battery::getLevel() const
{
    return levelPercent;
}

void Battery::showInfo() const
{
    cout << "Battery: " << capacitymAh << " mAh, Level: "
         << levelPercent << "%" << endl;
}
