#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <iostream>
using namespace std;

class Camera
{
public:
    enum class Position
    {
        FRONT,
        REAR
    };

private:
    int megapixels;
    Position position;

public:
    Camera(int mp = 12, Position pos = Position::REAR);

    void showInfo() const;

    // Getter
    int getMegapixels() const;
    Position getPosition() const;

    // Setter
    void setMegapixels(int mp);
    void setPosition(Position pos);
};

#endif
