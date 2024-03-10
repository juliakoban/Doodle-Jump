#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"
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

    Player* player = new Player("./assets/player_right.png", 0.6, 100, 100);

    float platformX = 0, platformY = 0;
    const int numberOfPlatforms = 7;

    std::vector<Entity*> platforms;
    for (int i = 0; i < numberOfPlatforms; i++) {
        platformX = rand() % (window_width - 70);
        platformY = i * (window_height / numberOfPlatforms);
        platforms.push_back(new Platform("./assets/platform.png", 1.2, platformX, platformY));
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

        player->update(platforms);
        // window.setView(sf::View(sf::FloatRect(0, player->y_, window_width, window_height)));

        if (player->y_ < window_height / 2) {
            player->y_ = window_height / 2;
            
            for (int i = 0; i < numberOfPlatforms; i++) {
               
                platforms.at(i)->y_ -= player->dy_;
                if (platforms.at(i)->y_ > window_height) {
                    platforms.at(i)->y_ = 0;
                    platforms.at(i)->x_ = rand() % (window_width - 70);
                }
                platforms.at(i)->sprite_.setPosition(platforms.at(i)->x_, platforms.at(i)->y_);
                platforms.at(i)->collider_->updatePosition(platforms.at(i)->x_, platforms.at(i)->y_);
            }
        }

        window.draw(background);
        player->draw(window);
        for(int i = 0; i < platforms.size(); i++) {
            platforms.at(i)->draw(window);
        }
        window.display();
    }

    delete player;
    for (auto ptr: platforms) {
        delete ptr;
    }
    platforms.clear();

    return 0;
}