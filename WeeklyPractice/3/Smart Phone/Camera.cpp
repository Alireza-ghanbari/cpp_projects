#include "Camera.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

Camera::Camera(int mp, Position pos)
    : megapixels(mp), position(pos) {}

void Camera::showInfo() const
{
    cout << "Camera (" << (position == Position::FRONT ? "front" : "rear")
         << "): " << megapixels << " MP" << endl;
}

// Getter
int Camera::getMegapixels() const
{
    return megapixels;
}

Camera::Position Camera::getPosition() const
{
    return position;
}

// Setter
void Camera::setMegapixels(int mp)
{
    if (mp > 0)
        megapixels = mp;
    else
        cout << "Invalid megapixel value!" << endl;
}

void Camera::setPosition(Position pos)
{
    position = pos;
}
