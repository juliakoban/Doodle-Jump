#include "Player.h"
#include "EntityState.h"

// const int window_width = 400;
// const int window_height = 533;

void Player::move(float dx, float dy) {
    
    x_ += dx;
    y_ += dy;
    
    if (x_ > window_width) {x_ = 0;}
    else if ((x_ + width_) < 0) {x_ = window_width;}

    sprite_.setPosition(x_, y_);
    this->collider_->updatePosition(this->x_, this->y_);
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
    else if (isDead()) {
        this->setState(new Death);
    } 
    else {this->setState(new IdleState);}
    
    state_->enter(this);
    state_->update(this);
    jumping_->enter(this);
    jumping_->update(this);
    
}

void Player::handleCollision() {
    this->dy_ = -10;
}

void Player::update() {
    this->handleState();
}

void Player::death() {
    this->x_ = window_width;
    this->y_ = window_height;
    this->sprite_.setPosition(x_, y_);
    delete this->jumping_;
    this->jumping_ = new IdleState; 
}

void Player::restart() {
    this->setPosition(100, 400);
    delete this->jumping_;
    this->jumping_ = new JumpingState;
}

bool Player::isDead() {
    if ((this->y_ + this->height_) >= window_height) {
        return true;
    }
    return false;
}
