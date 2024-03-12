#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player: public Entity {
private:
    EntityState* jumping_;
    
public:
    Player(const std::string path, float scale = 1, float x = 0, float y = 0, float dx = 0, float dy = 0) :
    Entity(path, scale, x, y, dx, dy), jumping_(new JumpingState) {collider_ = new Collider(x_, y_, width_, height_, 25, 0);}
    ~Player() {delete jumping_;}
    void handleState();
    void handleCollision();
    void move(float dx, float dy);
    void update();
};

#endif // PLAYER_H