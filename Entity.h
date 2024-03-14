#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "EntityState.h"
#include "Collider.h"

const int window_width = 400;
const int window_height = 533;

class Entity {
protected:
    sf::Texture texture_;
    sf::Sprite sprite_;
    float scale_;
    float width_, height_;
    float x_, y_;
    float dx_, dy_;
    EntityState* state_;
    Collider* collider_;
 
public:
    Entity(const std::string path, float scale = 1, float x = 0, float y = 0, float dx = 0, float dy = 0);
    ~Entity() {delete state_; delete collider_;}
    void draw(sf::RenderWindow &window);
    void changeSprite(const std::string path);
    void setState(EntityState* newState) {delete state_; state_ = newState;}
    void jump(float acceleration, float jumpHeight);
    virtual void move(float dx, float dy) {}
    virtual void handleState() {}
    virtual void handleCollision() {}
    virtual void update() {}
    bool collidesWith(Entity* other) {return collider_->intersects(other->collider_);}
    void death() {}
    void restart() {}
    float getY();
    float getX();
    float getWidth();
    float getHeight();
    float getDY();
    void setY(float y);
    void setX(float x);
    void setPosition(float x, float y);
    void subtractDyfromY(float dy);
};

class Platform: public Entity {
public:
    Platform(const std::string path, float scale = 1, float x = 0, float y = 0, float dx = 0, float dy = 0) :
    Entity(path, scale, x, y, dx, dy) {collider_ = new Collider(x_, y_, width_, height_, 0, -10);}
    void handleState();
    void move(float dx, float dy);
    void update();
    void restart();
};

#endif // ENTITY_H



