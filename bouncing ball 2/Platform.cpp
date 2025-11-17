#include "Platform.h"
#include "Settings.h"
#include <random>
#include <iostream>

void Platform::update(float dt)
{
	platformMovement(dt);
}

void Platform::platformMovement(float dt)
{
	m_platform.x += (static_cast<int>(IsKeyDown(KEY_D)) - static_cast<int>(IsKeyDown(KEY_A))) * m_speed * dt;
	m_platform.y += (static_cast<int>(IsKeyDown(KEY_S)) - static_cast<int>(IsKeyDown(KEY_W))) * m_speed * dt;

}

void Platform::draw() const
{
	/*float xPosition = randomizer();
	int counter{};
	for (float i = Settings::WINDOW_HEIGHT / 2; i > -Settings::WORLD_HEIGHT; i -= 200)
	{
		counter++;
		DrawRectangleV({ xPosition, i }, { m_platform.width, m_platform.height }, WHITE);
	}
	std::cout << counter << '\n';*/

	DrawRectangleRec(m_platform, WHITE);
}

//float Platform::randomizer()
//{
//	std::random_device rd;
//	std::mt19937 gen(rd());
//	std::uniform_int_distribution<> dist(0, Settings::WINDOW_WIDTH - 70);
//	return static_cast<float>(dist(gen));
//}
