#ifndef ENTITY_STATE_H
#define ENTITY_STATE_H

#include <SFML/Graphics.hpp>
#include <iostream>

// forward declaration of Entity class
class Entity;

class EntityState {
public:
    virtual void update(Entity* entity) = 0;
    virtual void enter(Entity* entity) = 0;
};

class IdleState: public EntityState {
public:
    void update(Entity* entity) override;
    void enter(Entity* entity) override;
};

class RightWalkingState: public EntityState {
private:
    float speed_ = 10.;
public:
    void update(Entity* entity) override;   
    void enter(Entity* entity) override;
};

class LeftWalkingState: public EntityState {
private:
    float speed_ = -10.;
public:
    void update(Entity* entity) override;
    void enter(Entity* entity) override;
};

class JumpingState: public EntityState {
private:
    float jumpHeight_ = -14.;
    float acceleration_ = 0.4;
public:
    void update(Entity* entity) override;
    void enter(Entity* entity) override;
};

class FiringState: public EntityState {
public:
    void update(Entity* entity) override;
    void enter(Entity* entity) override;
};

#endif // ENTITY_STATE_H
