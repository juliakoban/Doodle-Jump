#include "Game.h"

Game::Game() : window(sf::VideoMode(window_width, window_height), "Doodle Jump", sf::Style::Close | sf::Style::Titlebar),
    state(GameState::Menu) {
    window.setPosition(sf::Vector2i((screen_width/2) - (window_width / 2), (screen_height/2) - (window_height / 2)));
    window.setFramerateLimit(60);
    initalizeBackground();
    initalizeGameObjects();
    if (!font.loadFromFile("./assets/fonts/DoodleJump.ttf"))
    {
        std::cout << "Loading Font Error" << std::endl;
    }
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::Black);
    text.setPosition(window_width / 5, window_height / 3);
}

Game::~Game() {
    for (auto ptr: entities) {
        delete ptr;
    }
    entities.clear();
    delete collisionHandler;
    delete camera;
    delete score;
}

void Game::initalizeBackground() {
    background_texture.loadFromFile("./assets/sprites/background.png");
    background.setTexture(background_texture);
}

void Game::initalizeGameObjects() {
    collisionHandler = new CollisionHandler();
    camera = new Camera();
    score = new Score();

    float platformX = 0, platformY = 0;

    player = new Player("./assets/sprites/player_right.png", 0.6, 100, 400);
    entities.push_back(player);

    startingPlatform = new Platform("./assets/sprites/platform.png", 1.2, 100, 500); 

    entities.push_back(startingPlatform);

    for (int i = 0; i < (numberOfPlatforms - 1); i++) {
        platformX = rand() % int(window_width - startingPlatform->getWidth());
        platformY = i * (window_height / numberOfPlatforms);
        entities.push_back(new Platform("./assets/sprites/platform.png", 1.2, platformX, platformY));
    }
}

void Game::updateObjects() {
    collisionHandler->checkCollisions(entities);
    camera->movementSimulation(entities, score);

    for(int i = 0; i < static_cast<int>(entities.size()); i++) {
            entities.at(i)->update();
        }
}

void Game::drawScore() {
    window.draw(score->toText());
}

void Game::drawObjects() {
    window.draw(background);
    
    for(int i = 0; i < static_cast<int>(entities.size()); i++) {
            entities.at(i)->draw(window);
        }
    drawScore();
}

void Game::drawMenu() {
    text.setString("Press ENTER \n to START!");
    window.draw(background);
    window.draw(text);
}

void Game::drawEnd() {
    text.setString("Press ENTER \n to RESTART!");
    window.draw(background);
    window.draw(text);
}

void Game::handleInput() {
    if (state == GameState::Menu && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        state = GameState::Playing;
    }
    else if(state == GameState::Playing && player->isDead()) {
        state = GameState::End;
    }
    else if(state == GameState::End && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
        restart();
        state = GameState::Playing;
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
    score->restart();
    
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
