#pragma once
#include <raylib.h>

class Platform
{
private:
	Rectangle m_platform{330,300, 70, 10};
	float m_speed{ 300.0f };

public:
	Platform() = default;

	void update(float dt);
	void platformMovement(float dt);
	const Rectangle& getPlatform() const { return m_platform; }
	void draw() const;
	float randomizer();
};