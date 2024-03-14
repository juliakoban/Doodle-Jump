#include "Game.h"

Game::Game() : window(sf::VideoMode(window_width, window_height), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar),
    state(GameState::Menu) {
    window.setPosition(sf::Vector2i((screen_width/2) - (window_width / 2), (screen_height/2) - (window_height / 2)));
    window.setFramerateLimit(60);
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

    player = new Player("./assets/player_right.png", 0.6, 100, 400);
    entities.push_back(player);

    startingPlatform = new Platform("./assets/platform.png", 1.2, 100, 500); 

    entities.push_back(startingPlatform);

    for (int i = 0; i < (numberOfPlatforms - 1); i++) {
        platformX = rand() % int(window_width - startingPlatform->getWidth());
        platformY = i * (window_height / numberOfPlatforms);
        entities.push_back(new Platform("./assets/platform.png", 1.2, platformX, platformY));
    }
}

void Game::updateObjects() {
    collisionHandler->checkCollisions(entities);
    camera->movementSimulation(entities);

    for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->update();
        }
}
void Game::drawObjects() {
    window.draw(background);
    for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->draw(window);
        }
}

void Game::drawMenu() {
    window.draw(background);
}

void Game::drawEnd() {
    window.draw(background);
}

void Game::handleInput() {
    if (state == GameState::Menu && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        std::cout << "playing" << std::endl;
        state = GameState::Playing;
    }
    else if(state == GameState::Playing && player->isDead()) {
        std::cout << "death" << std::endl;
        reset();
        state = GameState::End;
    }
    else if(state == GameState::End && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        restart();
        state = GameState::Playing;
    }

}

void Game::reset() {
    for(int i = 0; i < entities.size(); i++) {
            entities.at(i)->setPosition(window_height, window_height);
        }
}

void Game::restart()
{   
    // score = 0;
    player->restart();
    startingPlatform->setPosition(100, 500);
    for(int i = 0; i < (numberOfPlatforms - 1); i++) {
            entities.at(i + 2)->setPosition(rand() % int(window_width - startingPlatform->getWidth()),
            i * (window_height / numberOfPlatforms));
        }
    
}

void Game::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        handleInput();

        switch (state) {
            case GameState::Menu:
                drawMenu();
                break;
            case GameState::Playing:
                updateObjects();
                drawObjects();
                break;
            case GameState::End:
                drawEnd();
                break;
        }
        window.display();
    }
}
