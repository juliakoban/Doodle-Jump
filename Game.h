#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Camera.h"
#include "CollisionHandler.h"
#include <iostream>
#include <vector>

const int screen_width = 1920;
const int screen_height = 1080;

class Game {
private:
    sf::RenderWindow window_;
    sf::Texture background_texture;
    sf::Sprite background;
    int numberOfPlatforms = 7;
    std::vector<Entity*> entities;
    Player* player;
    CollisionHandler* collisionHandler;
    Camera* camera;
public:
    Game();
    ~Game();
    void initalizeBackground();
    void initalizeGameObjects();
    void update();
    void draw();
    void run();
    
};

#endif // GAME_H