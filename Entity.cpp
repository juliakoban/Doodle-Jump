#include "Entity.h"
#include "Player.h"
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
    // collider_ = new Collider(x_, y_, width_, height_, 10, 10);
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
    this->collider_->updatePosition(this->x_, this->y_);
}

float Entity::getX() {
    return this->x_;
}

float Entity::getY() {
    return this->y_;
}

float Entity::getWidth() {
    return this->width_;
}

float Entity::getHeight() {
    return this->height_;
}

float Entity::getDY() {
    return this->dy_;
}

void Entity::setY(float y) {
    this->y_ = y;
}

void Entity::setX(float x) {
    this->x_ = x;
}

void Entity::subtractDyfromY(float dy) {
    this->y_ -= dy;
}

void Platform::handleState() {
    
}

void Platform::move(float dx, float dy) {

}

void Platform::update() {
    this->sprite_.setPosition(this->x_, this->y_);
    this->collider_->updatePosition(this->x_, this->y_);
}