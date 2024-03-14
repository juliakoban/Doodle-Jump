#include "Game.h"

Game::Game() : window_(sf::VideoMode(window_width, window_height), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar) {
    window_.setPosition(sf::Vector2i((screen_width/2) - (window_width / 2), (screen_height/2) - (window_height / 2)));
    window_.setFramerateLimit(60);
    initalizeBackground();
    initalizeGameObjects();
}

Game::~Game() {
    for (auto ptr: entities) {
        delete ptr;
    }
    entities.clear();
    delete collisionHandler;
    delete camera;
}

void Game::initalizeBackground() {
    background_texture.loadFromFile("./assets/background.png");
    background.setTexture(background_texture);
}

void Game::initalizeGameObjects() {
    collisionHandler = new CollisionHandler();
    camera = new Camera();

    float platformX = 0, platformY = 0;
    float platformWidth = 70, platformHeight = 30;

    player = new Player("./assets/player_right.png", 0.6, 100, 100);
    entities.push_back(player);

    entities.push_back(new Platform("./assets/platform.png", 1.2, 100, 500));
    for (int i = 0; i < (numberOfPlatforms - 1); i++) {
        platformX = rand() % int(window_width - platformWidth);
        platformY = i * (window_height / numberOfPlatforms);
        entities.push_back(new Platform("./assets/platform.png", 1.2, platformX, platformY));
    }
}

void Game::update() {
    for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->update();
        }
}
void Game::draw() {
    window_.draw(background);
    for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->draw(window_);
        }
}

void Game::run() {
    while (window_.isOpen()) {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        // update entities, handle camera and collisions
        collisionHandler->checkCollisions(entities);
        camera->movementSimulation(entities);
        update();
        draw();

        window_.display();
    }
}
