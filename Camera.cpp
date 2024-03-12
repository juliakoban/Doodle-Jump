#include "Camera.h"

void Camera::movementSimulation(std::vector<Entity*> gameobjects) {
    if (gameobjects.at(0)->getY() < window_height / 2) {
        gameobjects.at(0)->setY(window_height / 2);

        for (int i = 1; i < gameobjects.size(); i++) {
                gameobjects.at(i)->subtractDyfromY(gameobjects.at(0)->getDY());
                if (gameobjects.at(i)->getY() > window_height) {
                    gameobjects.at(i)->setY(0);
                    gameobjects.at(i)->setX(rand() % (window_width - 70));
                }
            }
    }
}