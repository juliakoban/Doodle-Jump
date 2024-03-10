#ifndef COLLIDER_H
#define COLLIDER_H

class Collider {
private:
    float x_, y_;
    float width_, height_;
    float offsetX_ = 0, offsetY_ = 0;
    float top, bottom, left, right;
public:
    Collider(float x, float y, float width, float height, float offsetX, float offsetY);
    ~Collider() {}
    bool intersects(Collider* other);
    void updatePosition(float x, float y);
};

#endif // COLLIDER_H
