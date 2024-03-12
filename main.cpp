#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
#include "Camera.h"
#include "CollisionHandler.h"
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    const int window_width = 400;
    const int window_height = 533;

    const int screen_width = 1920;
    const int screen_height = 1080;

    // create the window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar);

    // change the position of the window (relatively to the desktop)
    window.setPosition(sf::Vector2i((screen_width/2) - (window_width / 2), (screen_height/2) - (window_height / 2)));

    window.setFramerateLimit(60);

    sf::Texture background_texture;
    background_texture.loadFromFile("./assets/background.png");
    sf::Sprite background(background_texture);

    // initializing objects
    CollisionHandler* collisionHandler = new CollisionHandler();
    Camera* camera = new Camera();
    Player* player = new Player("./assets/player_right.png", 0.6, 100, 100);

    float platformX = 0, platformY = 0;
    const int numberOfPlatforms = 7;

    // std::vector<Entity*> platforms;
    std::vector<Entity*> entities;
    entities.push_back(player);
    for (int i = 0; i < numberOfPlatforms; i++) {
        platformX = rand() % (window_width - 70);
        platformY = i * (window_height / numberOfPlatforms);
        entities.push_back(new Platform("./assets/platform.png", 1.2, platformX, platformY));
    }

    // run the program as long as the window is open
    while(window.isOpen()){

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // updating objects
        collisionHandler->checkCollisions(entities);
        camera->movementSimulation(entities);

        for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->update();
        }

        // drawing objects
        window.draw(background);
        for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->draw(window);
        }
        window.display();
    }

    // clearing memory
    delete collisionHandler, camera;
    for (auto ptr: entities) {
        delete ptr;
    }
    entities.clear();

    return 0;
}