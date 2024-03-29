#include "EntityState.h"
#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

void IdleState::update(Entity* entity) {
    // std::cout << "Handling idle state" << std::endl;   
}
void IdleState::enter(Entity* entity) {
    // entity.changeSprite("./assets/player_right.png");
    // std::cout << "Entering idle state" << std::endl;   
}

void RightWalkingState::update(Entity* entity) {
    entity->move(speed_, 0);
    // std::cout << "Handling right walking state" << std::endl;    
}
void RightWalkingState::enter(Entity* entity) {
    entity->changeSprite("./assets/sprites/player_right.png");
    // std::cout << "Entering right walking state" << std::endl;  
}

void LeftWalkingState::update(Entity* entity) {
    entity->move(speed_, 0);
    // std::cout << "Handling left walking state" << std::endl;
}
void LeftWalkingState::enter(Entity* entity) {
    entity->changeSprite("./assets/sprites/player_left.png");
    // std::cout << "Entering left walking state" << std::endl;
}

void JumpingState::update(Entity* entity) {
    entity->jump(acceleration_, jumpHeight_);
    // std::cout << "Handling jumping state" << std::endl;
}
void JumpingState::enter(Entity* entity) {
    // std::cout << "Entering jumping state" << std::endl;
}

void FiringState::update(Entity* entity) {
    // std::cout << "Handling firing state" << std::endl;
}
void FiringState::enter(Entity* entity) {
    entity->changeSprite("./assets/sprites/player_firing.png");
    // std::cout << "Entering firing state" << std::endl;
}

void Death::update(Entity* entity) {
    entity->death();
    // if (Player* player = dynamic_cast<Player*>(entity)) {
    //     std::cout <<"special action for player" << std::endl;
    // }
}
void Death::enter(Entity* entity) {
    entity->changeSprite("./assets/sprites/empty_sprite.png");
}


