#include "Score.h"
#include <iostream>
#include <string>

const int window_width = 400;
const int window_height = 533;

Score::Score() {
    if (!font.loadFromFile("./assets/fonts/DoodleJump.ttf"))
    {
        std::cout << "Loading Font Error" << std::endl;
    }
    scoreText.setFont(font);
    scoreText.setCharacterSize(40);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setStyle(sf::Text::Bold);
    scoreText.setPosition(10, -10);
}

Score::~Score() {

}

void Score::restart() {
    score = 0;
}

sf::Text Score::toText() {
    std::string score_text = std::to_string(score);
    scoreText.setString(score_text);
    return scoreText;
}

void Score::update() {
    score += 10;
}