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

enum GameState {
    Menu,
    Playing,
    End
};

class Game {
private:
    sf::RenderWindow window;
    sf::Texture background_texture;
    sf::Sprite background;
    int numberOfPlatforms = 7;
    std::vector<Entity*> entities;
    Player* player;
    Platform* startingPlatform;
    CollisionHandler* collisionHandler;
    Camera* camera;
    GameState state;
public:
    Game();
    ~Game();
    void initalizeBackground();
    void initalizeGameObjects();
    void updateObjects();
    void drawObjects();
    void drawMenu();
    void drawEnd();
    void handleInput();
    void restart();
    void reset();
    void run();
    
};

#endif // GAME_H