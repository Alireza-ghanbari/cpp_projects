#include "CPU.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

CPU::CPU(int c, double f, string cr)
    : cores(c), frequencyGHz(f), creator(cr) {}

void CPU::showInfo() const
{
    cout << "CPU: " << cores << " cores, " << frequencyGHz
         << " GHz, created by: " << creator << endl;
}

// Getter

int CPU::getCores() const
{
    return cores;
}

double CPU::getFrequencyGHz() const
{
    return frequencyGHz;
}

string CPU::getCreator() const
{
    return creator;
}

// Setter

void CPU::setCores(int c)
{
    if (c > 0)
        cores = c;
    else
        cout << "Invalid core count!" << endl;
}

void CPU::setFrequencyGHz(double f)
{
    if (f > 0)
        frequencyGHz = f;
    else
        cout << "Invalid frequency value!" << endl;
}

void CPU::setCreator(const string cr)
{
    if (!cr.empty())
        creator = cr;
    else
        cout << "Creator name cannot be empty!" << endl;
}
