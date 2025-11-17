#pragma once
#include <raylib.h>
#include "Settings.h"

class Ball
{
private:
    float m_size{ 10 };
    Vector2 m_position{ 375 , 250 };
    Vector2 m_velocity{ 0, 0 };
    Vector2 m_gravity{ 0, 900 };
    float m_inputAcceleration{ 1200 };
    bool m_charging{ false };
    float m_chargeAcceleration{ 1000 };
    bool m_speedLimit{ true };

public:
    Ball() = default;

    void update(float dt);
    void checkCollision();
    void limitVelocity();
    void inputHandling(float dt);
    void updateVelocityAndPosition(float dt);
    void charging(float dt, Vector2 position);
    void toggleVelocityLimit();
    void resetPosition();
    const Vector2& getPosition() const { return m_position; }
    float getRadius() const { return m_size; }
    void setPositionX(float x) { m_position.x = x; };
    void setPositionY(float y) { m_position.y = y; };
    const Vector2& getVelocity() const { return m_velocity; }
    void invertVelocityY() { m_velocity.y = -m_velocity.y; }
    void invertVelocityX() { m_velocity.x = -m_velocity.x; }
    void draw() const { DrawCircleV(m_position, m_size, WHITE); }
};