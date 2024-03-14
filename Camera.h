#ifndef CAMERA_H
#define CAMERA_H

#include <vector>
#include "Entity.h"
#include "Score.h"

class Camera {
public:
    void movementSimulation(std::vector<Entity*> gameobjects, Score* score);
};

#endif // CAMERA_H