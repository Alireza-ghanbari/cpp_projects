#ifndef CPU_H
#define CPU_H

#include <string>

using namespace std;

class CPU
{
private:
    int cores;
    double frequencyGHz;
    string creator;

public:
    CPU(int c = 4, double f = 2.0, string creator = "Intel");

    void showInfo() const;

    int getCores() const;
    double getFrequencyGHz() const;
    string getCreator() const;

    void setCores(int c);
    void setFrequencyGHz(double f);
    void setCreator(const string creator);
};

#endif