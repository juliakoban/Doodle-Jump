#include "CollisionHandler.h"

void CollisionHandler::checkCollisions(std::vector<Entity*> gameobjects) {
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < static_cast<int>(gameobjects.size()); j++) {
            if (i != j && gameobjects.at(i)->collidesWith(gameobjects.at(j))) {
                gameobjects.at(i)->handleCollision();
                gameobjects.at(j)->handleCollision();
            }
        }
    }
}