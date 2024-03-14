#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Entity.h"

class Camera {
public:
    void movementSimulation(std::vector<Entity*> gameobjects);
};

#endif // CAMERA_H