#ifndef SCORE_H
#define SCORE_H

#include <SFML/Graphics.hpp>

class Score {
private:
    sf::Text scoreText;
    sf::Font font;
    int score = 0;
public:
    Score();
    ~Score();
    void update();
    void restart();
    sf::Text toText();
};

#endif // SCORE_H