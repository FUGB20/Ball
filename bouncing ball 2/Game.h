#pragma once
#include <raylib.h>
#include "Ball.h"
#include "Platform.h"
#include <vector>

class Game
{
private:
	Ball m_ball{};
	Platform m_platform{};
	float m_dt{};
	int counter{ 1 };
	Camera2D m_camera{ {Settings::WINDOW_WIDTH / 2, Settings::WINDOW_HEIGHT / 2}, m_ball.getPosition(), 0, 1};
	Texture2D m_background{ LoadTexture("C:\\Users\\Dell\\Downloads\\assets\\Clouds\\Clouds 4\\1.png") };

public:
	Game() = default;

	void update();
	void cameraUpdate();
	Camera2D& getCamera() { return m_camera; }
	void checkPlatformCollision();
	void checkPlatformCollisionAbove();
	void checkPlatformCollisionBelow();
	void checkPlatformCollisionRight();
	void checkPlatformCollisionLeft();
	void draw() const;
};