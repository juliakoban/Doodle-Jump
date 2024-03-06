#include <SFML/Graphics.hpp>
#include "Entity.h"
#include <iostream>

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
    
    Player player("./assets/player_right.png", 0.6, 100, 100, 10);

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

        player.handleState();

        window.draw(background);
        player.draw(window);

        window.display();

    }

    return 0;
}