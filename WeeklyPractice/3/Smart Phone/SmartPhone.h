#ifndef SMARTPHONE_H
#define SMARTPHONE_H

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
    string model;
    CPU cpu;
    Battery battery;
    Screen screen;
    Camera frontCamera;
    Camera rearCamera;
    OS os;

public:
    SmartPhone(string m = "Iphone 17 pro");

    void showInfo() const;
    void chargeBattery(double percent);
    void useBattery(double percent);

    // Getter
    string getModel() const;
    CPU getCPU() const;
    Battery getBattery() const;
    Screen getScreen() const;
    Camera getFrontCamera() const;
    Camera getRearCamera() const;
    OS getOS() const;

    // Setter
    void setModel(const string &m);
    void setCPU(const CPU &c);
    void setBattery(const Battery &b);
    void setScreen(const Screen &s);
    void setFrontCamera(const Camera &c);
    void setRearCamera(const Camera &c);
    void setOS(const OS &o);
};

#endif