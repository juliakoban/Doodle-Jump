#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Player.h"
#include "Camera.h"
#include "Score.h"
#include "CollisionHandler.h"
#include <iostream>
#include <vector>
#include <string>

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
    sf::Text text;
    sf::Font font;
    int numberOfPlatforms = 7;
    std::vector<Entity*> entities;
    Player* player;
    Platform* startingPlatform;
    CollisionHandler* collisionHandler;
    Camera* camera;
    GameState state;
    Score* score;
public:
    Game();
    ~Game();
    void initalizeBackground();
    void initalizeGameObjects();
    void updateObjects();
    void drawScore();
    void drawObjects();
    void drawMenu();
    void drawEnd();
    void handleInput();
    void restart();
    void run();
    
};

#endif // GAME_H