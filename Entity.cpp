#include "Entity.h"
#include "EntityState.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

const int window_width = 400;
const int window_height = 533;

Entity::Entity(const std::string path, float scale, float x, float y, float dx, float dy){
    texture_.loadFromFile(path);
    sprite_.setTexture(texture_);
    scale_ = scale;
    sprite_.setScale(scale_, scale_);
    width_ = texture_.getSize().x * scale_;
    height_ = texture_.getSize().y * scale_;
    x_ = x;
    y_ = y;
    dx_ = dx;
    dy_ = dy;
    sprite_.setPosition(x_, y_);
    state_ = new IdleState();
}

void Entity::draw(sf::RenderWindow &window){
    window.draw(sprite_);
}

void Entity::changeSprite(const std::string path) {
    texture_.loadFromFile(path);
    sprite_.setTexture(texture_);
}

void Entity::jump(float acceleration, float jumpHeight) {
    dy_ += acceleration;
    y_ += dy_;
    if (y_ > (window_height - height_)) {dy_ = jumpHeight;}
    sprite_.setPosition(x_, y_);
}

void Player::move(float dx, float dy) {
    x_ += dx;
    y_ += dy;

    if (x_ > window_width) {x_ = 0;}
    else if ((x_ + width_) < 0) {x_ = window_width;}

    sprite_.setPosition(x_, y_);
}

void Player::handleState() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        this->setState(new RightWalkingState);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        this->setState(new LeftWalkingState);
    } 
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        this->setState(new FiringState);
    } 
    else {this->setState(new IdleState);}
    
    state_->enter(*this);
    state_->update(*this);
    jumping_->enter(*this);
    jumping_->update(*this);
    
}