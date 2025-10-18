#include <iostream>
#include "Camera.h"
using namespace std;

int main()
{
    Camera rearCam;
    rearCam.showInfo();

    Camera frontCam(16, Camera::Position::FRONT);
    frontCam.showInfo();

    rearCam.setMegapixels(64);
    rearCam.setPosition(Camera::Position::REAR);

    cout << "\nAfter updating rear camera:\n";
    rearCam.showInfo();

    return 0;
}
