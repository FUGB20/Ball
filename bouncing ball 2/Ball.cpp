#include <raylib.h>
#include "Ball.h"
#include "Settings.h"
#include <iostream>

void Ball::update(float dt)
{
	charging(dt, m_position);
	if (m_charging == false)
	{
		toggleVelocityLimit();
		updateVelocityAndPosition(dt);
		if (m_speedLimit == true)
		{
			limitVelocity();
		}
		inputHandling(dt);
		checkCollision();
		resetPosition();
	}
}

void Ball::checkCollision()
{
	if (m_position.x - m_size < 0)
	{
		m_position.x = m_size;
		invertVelocityX();
	}
	else if (m_position.x + m_size > Settings::WINDOW_WIDTH)
	{
		m_position.x = Settings::WINDOW_WIDTH - m_size;
		invertVelocityX();
	}

	if (m_position.y - m_size < 0)
	{
		//m_position.y = m_size;
		//invertVelocityY();
	}
	else if (m_position.y + m_size > Settings::WINDOW_HEIGHT)
	{
		m_position.y = Settings::WINDOW_HEIGHT - m_size;
		m_velocity.y *= -0.8f;
		m_velocity.x *= 0.999f;
	}
}

void Ball::limitVelocity()
{
	if (m_velocity.y > Settings::MAX_SPEED)
	{
		m_velocity.y = Settings::MAX_SPEED;
	}
	else if (m_velocity.y < -Settings::MAX_SPEED)
	{
		m_velocity.y = -Settings::MAX_SPEED;
	}
	if (m_velocity.x > Settings::MAX_SPEED)
	{
		m_velocity.x = Settings::MAX_SPEED;
	}
	else if (m_velocity.x < -Settings::MAX_SPEED)
	{
		m_velocity.x = -Settings::MAX_SPEED;
	}
}

void Ball::inputHandling(float dt)
{
	m_velocity.x += (static_cast<int>(IsKeyDown(KEY_RIGHT)) - static_cast<int>(IsKeyDown(KEY_LEFT)))
		* m_inputAcceleration * dt;
	m_velocity.y += (static_cast<int>(IsKeyDown(KEY_DOWN)) - static_cast<int>(IsKeyDown(KEY_UP)))
		* m_inputAcceleration * dt;
}

void Ball::updateVelocityAndPosition(float dt)
{
	m_velocity.x = m_velocity.x + m_gravity.x * dt;
	m_velocity.y = m_velocity.y + m_gravity.y * dt;

	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;
}

void Ball::charging(float dt, Vector2 position)
{
	if (IsKeyDown(KEY_SPACE))
	{
		m_charging = true;
		m_velocity.y -= m_chargeAcceleration * dt;
		m_position = position;
	}
	else
	{
		m_charging = false;
		m_chargeAcceleration = 2500;
	}
}

void Ball::toggleVelocityLimit()
{
	if (IsKeyPressed(KEY_L))
	{
		m_speedLimit = !m_speedLimit;
	}
}

void Ball::resetPosition()
{
	if (IsKeyPressed(KEY_R))
	{
		m_position = { 375 , 250 };
		m_velocity = { 0, 0 };
		m_gravity = { 0, 500 };
	}
}