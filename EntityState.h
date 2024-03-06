#ifndef ENTITY_STATE_H
#define ENTITY_STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>

// forward declaration of Entity class
class Entity;

class EntityState {
public:
    virtual void update(Entity& entity) = 0;
    virtual void enter(Entity& entity) = 0;
};

class IdleState: public EntityState {
public:
    void update(Entity& entity) override;
    void enter(Entity& entity) override;
};

class RightWalkingState: public EntityState {
public:
    void update(Entity& entity) override;   
    void enter(Entity& entity) override;
};

class LeftWalkingState: public EntityState {
public:
    void update(Entity& entity) override;
    void enter(Entity& entity) override;
};

class JumpingState: public EntityState {
private:
    float jumpHeight = -10.;
    float acceleration = 0.2;
public:
    void update(Entity& entity) override;
    void enter(Entity& entity) override;
};

#endif // ENTITY_STATE_H
