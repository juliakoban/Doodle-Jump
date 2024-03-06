#include "Entity.h"
#include "EntityState.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

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