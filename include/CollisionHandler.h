#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include <vector>
#include "Entity.h"

class CollisionHandler {
public:
    CollisionHandler() {}
    ~CollisionHandler() {}
    void checkCollisions(std::vector<Entity*> gameObjects);
};

#endif // COLLISION_HANDLER_H