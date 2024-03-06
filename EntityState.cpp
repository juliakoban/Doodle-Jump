#include "EntityState.h"
#include "Entity.h"
#include <SFML/Graphics.hpp>

void IdleState::update(Entity& entity) {
    std::cout << "Handling idle state" << std::endl;   
}
void IdleState::enter(Entity& entity) {
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
    std::cout << "Handling jumping state" << std::endl;
}

void JumpingState::enter(Entity& entity) {
    std::cout << "Entering jumping state" << std::endl;
}


