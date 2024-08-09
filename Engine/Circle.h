#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

#include "MathHelper.h"

class Circle {
private:
    Vector2F position;
    float radius;
    Vector2F velocity;

public:
    Circle(const Vector2F& position, float radius, const Vector2F& velocity)
        : position(position), radius(radius), velocity(velocity) {}

    const Vector2F& getPosition() const {
        return position;
    }

    float getRadius() const {
        return radius;
    }

    const Vector2F& getVelocity() const {
        return velocity;
    }

    void setVelocity(const Vector2F& newVelocity) {
        velocity = newVelocity;
    }
};

#endif // CIRCLE_H
