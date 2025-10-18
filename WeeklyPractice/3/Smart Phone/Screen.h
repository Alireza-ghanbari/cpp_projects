#ifndef SCREEN_H
#define SCREEN_H

#include <string>

using namespace std;

class Screen
{
private:
    double sizeInches;
    enum panelType
    {
        LCD,
        OLED
    };
    string resolution;

public:
    Screen();
};

#endif