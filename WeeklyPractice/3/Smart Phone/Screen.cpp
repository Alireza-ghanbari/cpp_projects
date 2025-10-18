#include "Screen.h"
#include <iostream>
using namespace std;

Screen::Screen(double size, string res, PanelType type)
    : sizeInches(size), resolution(res), panel(type) {}

void Screen::showInfo() const
{
    cout << "Screen: " << sizeInches << " Inches "
         << resolution << " ("
         << (panel == PanelType::LCD ? "LCD" : "OLED")
         << ")" << endl;
}

// Getter
double Screen::getSize() const
{
    return sizeInches;
}

string Screen::getResolution() const
{
    return resolution;
}

Screen::PanelType Screen::getPanelType() const
{
    return panel;
}

// Setter
void Screen::setSize(double size)
{
    if (size > 0)
        sizeInches = size;
    else
        cout << "Invalid screen size!" << endl;
}

void Screen::setResolution(const string res)
{
    if (!res.empty())
        resolution = res;
    else
        cout << "Resolution cannot be empty!" << endl;
}

void Screen::setPanelType(PanelType type)
{
    panel = type;
}
