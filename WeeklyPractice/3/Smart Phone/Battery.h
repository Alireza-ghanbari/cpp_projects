#ifndef BATTERY_H
#define BATTERY_H

#include <string>

using namespace std;

class Battery
{
private:
    int capacitymAh;
    double levelPercent;

public:
    Battery(int capacity = 3000, double level = 100.0);

    double getLevel() const;
    void showInfo() const;
};

#endif