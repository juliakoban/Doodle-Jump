#include "Collider.h"
#include <iostream>


Collider::Collider(float x, float y, float width, float height, float offsetX, float offsetY) {
    offsetX_ = offsetX;
    offsetY_ = offsetY;
    x_ = x + offsetX_;
    y_ = y - offsetY_;
    width_ = width - 2 * offsetX_;
    height_ = height + offsetY_;
    top = y_;
    bottom = y_ + height_;
    left = x_;
    right = x_ + width_;

}

void Collider::updatePosition(float x, float y) {
    this->x_ = x + offsetX_;
    this->y_ = y + offsetY_;
    this->top = y_;
    this->bottom = y_ + height_;
    this->left = x_;
    this->right = x_ + width_;
    
}

bool Collider::intersects(Collider* other) {
  
    bool upCollision = this->bottom > other->top && this->bottom < other->bottom;
    // bool downCollision = this->bottom > other->top && this->bottom < other->bottom;
    bool horizontalCollision = this->left < other->right && this->right > other->left;

    if (upCollision && horizontalCollision) {
        // std::cout << " up collision" << std::endl;
        // std::cout << left << " " << top << " " << right << " " << bottom << std::endl;
        return true;
    }
    return false;
}