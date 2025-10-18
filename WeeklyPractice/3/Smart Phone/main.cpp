#include <iostream>
#include "Battery.h"

using namespace std;

int main()
{
    Battery battery(5000, 80);
    battery.showInfo();

    battery.drain(50);
    cout << "Battery level: " << battery.getLevel() << endl;

    battery.charge(80);
    cout << "Battery level: " << battery.getLevel() << endl;

    battery.drain(100);
    battery.showInfo();

    return 0;
}
