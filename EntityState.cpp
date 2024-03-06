#include "EntityState.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

const int window_width = 400;
const int window_height = 533;

void IdleState::update(Entity& entity) {
    std::cout << "Handling idle state" << std::endl;   
}
void IdleState::enter(Entity& entity) {
    // entity.changeSprite("./assets/player_right.png");
    std::cout << "Entering idle state" << std::endl;   
}

void RightWalkingState::update(Entity& entity) {
    entity.x_ += entity.dx_;
    entity.sprite_.setPosition(entity.x_, entity.y_);
    std::cout << "Handling right walking state" << std::endl;    
}
void RightWalkingState::enter(Entity& entity) {
    entity.changeSprite("./assets/player_right.png");
    std::cout << "Entering right walking state" << std::endl;  
}

void LeftWalkingState::update(Entity& entity) {
    entity.x_ -= entity.dx_;
    entity.sprite_.setPosition(entity.x_, entity.y_);
    std::cout << "Handling left walking state" << std::endl;
}
void LeftWalkingState::enter(Entity& entity) {
    entity.changeSprite("./assets/player_left.png");
    std::cout << "Entering left walking state" << std::endl;
}

void JumpingState::update(Entity& entity) {
    entity.dy_ += acceleration;
    entity.y_ += entity.dy_;
    if (entity.y_ > (window_height - entity.height_)) {entity.dy_ = jumpHeight;}
    entity.sprite_.setPosition(entity.x_, entity.y_);
    std::cout << "Handling jumping state" << std::endl;
}

void JumpingState::enter(Entity& entity) {
    std::cout << "Entering jumping state" << std::endl;
}

void FiringState::update(Entity& entity) {
    std::cout << "Handling firing state" << std::endl;
}
void FiringState::enter(Entity& entity) {
    entity.changeSprite("./assets/player_firing.png");
    std::cout << "Entering firing state" << std::endl;
}


