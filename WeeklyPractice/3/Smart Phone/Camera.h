#ifndef CAMERA_H
#define CAMERA_H

#include <string>

using namespace std;

class Camera
{
private:
    int megapixels;
    enum position
    {
        front,
        rear
    };

public:
    Camera();
};

#endif