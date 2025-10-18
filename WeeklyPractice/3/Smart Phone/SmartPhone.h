#ifndef SMARTPHONE_H
#define SMARTPHONE_H

#include <string>
#include <string>
#include "CPU.h"
#include "Battery.h"
#include "Screen.h"
#include "Camera.h"
#include "OS.h"

using namespace std;

class SmartPhone
{
private:
    CPU cpu;
    Battery battery;
    Screen screen;
    Camera frontCamera;
    Camera rearCamera;
    OS os;

public:
    SmartPhone();
};

#endif