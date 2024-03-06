#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player: public Entity {
protected:
    EntityState* jumping_;
    
public:
    Player(const std::string path, float scale = 1, float x = 0, float y = 0, float dx = 0, float dy = 0) :
    Entity(path, scale, x, y, dx, dy), jumping_(new JumpingState) {}
    ~Player() {delete jumping_;}
    void handleState();
    void move(float dx, float dy);
};

#endif // PLAYER_H