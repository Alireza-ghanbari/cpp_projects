#include "SmartPhone.h"
#include <iostream>
using namespace std;

SmartPhone::SmartPhone(string m)
    : model(m),
      cpu(8, 3.2, "Intel"),
      battery(5000, 100),
      screen(6.7, "1440x3200", Screen::PanelType::OLED),
      frontCamera(32, Camera::Position::FRONT),
      rearCamera(108, Camera::Position::REAR),
      os("IOS", "15.0") {}

void SmartPhone::showInfo() const
{
    cout << "\n ********* " << model << " STATUS *********" << endl;
    cpu.showInfo();
    battery.showInfo();
    screen.showInfo();
    frontCamera.showInfo();
    rearCamera.showInfo();
    os.showInfo();
    cout << "***************************" << endl;
}

void SmartPhone::chargeBattery(double percent)
{
    cout << "Charging phone by " << percent << "%..." << endl;
    battery.charge(percent);
    cout << "Battery level is now: " << battery.getLevel() << "%" << endl;
}

void SmartPhone::useBattery(double percent)
{
    cout << "Using " << percent << "% battery..." << endl;
    battery.drain(percent);
    cout << "Remaining battery: " << battery.getLevel() << "%" << endl;
}

string SmartPhone::getModel() const { return model; }
CPU SmartPhone::getCPU() const { return cpu; }
Battery SmartPhone::getBattery() const { return battery; }
Screen SmartPhone::getScreen() const { return screen; }
Camera SmartPhone::getFrontCamera() const { return frontCamera; }
Camera SmartPhone::getRearCamera() const { return rearCamera; }
OS SmartPhone::getOS() const { return os; }

void SmartPhone::setModel(const string &m) { model = m; }
void SmartPhone::setCPU(const CPU &c) { cpu = c; }
void SmartPhone::setBattery(const Battery &b) { battery = b; }
void SmartPhone::setScreen(const Screen &s) { screen = s; }
void SmartPhone::setFrontCamera(const Camera &c) { frontCamera = c; }
void SmartPhone::setRearCamera(const Camera &c) { rearCamera = c; }
void SmartPhone::setOS(const OS &o) { os = o; }
