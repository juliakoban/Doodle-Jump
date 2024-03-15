#include "Camera.h"


void Camera::movementSimulation(std::vector<Entity*> gameobjects, Score* score) {
    if (gameobjects.at(0)->getY() < window_height / 2) {
        gameobjects.at(0)->setY(window_height / 2);

        for (int i = 1; i < static_cast<int>(gameobjects.size()); i++) {
                gameobjects.at(i)->subtractDyfromY(gameobjects.at(0)->getDY());
                if (gameobjects.at(i)->getY() > window_height) {
                    gameobjects.at(i)->setY(0);
                    gameobjects.at(i)->setX(rand() % int(window_width - gameobjects.at(i)->getWidth()));
                    score->update();
                }
            }
    }
}