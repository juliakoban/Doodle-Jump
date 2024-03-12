#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Entity.h"

const int window_width = 400;
const int window_height = 533;

const int screen_width = 1920;
const int screen_height = 1080;

class Camera {
public:
    void movementSimulation(std::vector<Entity*> gameobjects);
};

#endif // CAMERA_H