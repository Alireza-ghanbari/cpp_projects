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

    void drain(double percent);
    void charge(double percent);
    double getLevel() const;
    void showInfo() const;
};

#endif