#include "Game.h"

void Game::update()
{
	m_dt = GetFrameTime();
	m_ball.update(m_dt);
	m_platform.update(m_dt);
	cameraUpdate();
	checkPlatformCollision();
}

void Game::cameraUpdate()
{
	m_camera.target.y = m_ball.getPosition().y;

	if (m_camera.target.y >= Settings::WINDOW_HEIGHT / 2)
	{
		m_camera.target.y = Settings::WINDOW_HEIGHT / 2;
	}
}

void Game::checkPlatformCollision()
{
	if (CheckCollisionCircleRec(m_ball.getPosition(), m_ball.getRadius(), m_platform.getPlatform()))
	{
		checkPlatformCollisionAbove();
		checkPlatformCollisionBelow();
		checkPlatformCollisionRight();
		checkPlatformCollisionLeft();
	}
}

void Game::checkPlatformCollisionAbove()
{
	if ((m_ball.getPosition().y + m_ball.getRadius()) > (m_platform.getPlatform().y) && // the tangent of the ball
		m_ball.getPosition().x > m_platform.getPlatform().x && // platform interval 1
		m_ball.getPosition().x < m_platform.getPlatform().x + m_platform.getPlatform().width && // platform interval 2
		m_ball.getPosition().y < m_platform.getPlatform().y && // center of the ball
		m_ball.getVelocity().y > 0) // direction of the ball
	{
		m_ball.setPositionY(m_platform.getPlatform().y - m_ball.getRadius());
		m_ball.invertVelocityY();
	}
}

void Game::checkPlatformCollisionBelow()
{
	if ((m_ball.getPosition().y - m_ball.getRadius()) < (m_platform.getPlatform().y + m_platform.getPlatform().height) && // the tangent of the ball
		m_ball.getPosition().x > m_platform.getPlatform().x && // platform interval 1
		m_ball.getPosition().x < m_platform.getPlatform().x + m_platform.getPlatform().width && // platform interval 2
		m_ball.getPosition().y > m_platform.getPlatform().y + m_platform.getPlatform().height && // center of the ball
		m_ball.getVelocity().y < 0) // direction of the ball
	{
		m_ball.setPositionY(m_platform.getPlatform().y + m_platform.getPlatform().height + m_ball.getRadius());
		m_ball.invertVelocityY();
	}
}

void Game::checkPlatformCollisionRight()
{
	if ((m_ball.getPosition().x + m_ball.getRadius()) > (m_platform.getPlatform().x) && // the tangent of the ball
		m_ball.getPosition().y > m_platform.getPlatform().y && // platform interval 1
		m_ball.getPosition().y < m_platform.getPlatform().y + m_platform.getPlatform().height && // platform interval 2
		m_ball.getPosition().x < m_platform.getPlatform().x && // center of the ball
		m_ball.getVelocity().x > 0) // direction of the ball
	{
		m_ball.setPositionX(m_platform.getPlatform().x - m_ball.getRadius());
		m_ball.invertVelocityX();
	}
}

void Game::checkPlatformCollisionLeft()
{
	if ((m_ball.getPosition().x - m_ball.getRadius()) < (m_platform.getPlatform().x + m_platform.getPlatform().width) && // the tangent of the ball
		m_ball.getPosition().y > m_platform.getPlatform().y && // platform interval 1
		m_ball.getPosition().y < m_platform.getPlatform().y + m_platform.getPlatform().height && // platform interval 2
		m_ball.getPosition().x > m_platform.getPlatform().x + m_platform.getPlatform().width && // center of the ball
		m_ball.getVelocity().x < 0) // direction of the ball
	{
		m_ball.setPositionX(m_platform.getPlatform().x + m_platform.getPlatform().width + m_ball.getRadius());
		m_ball.invertVelocityX();
	}
}

void Game::draw() const
{
	for (int i = 0; i < Settings::WINDOW_WIDTH; i += m_background.width)
	{
		for (int j = 600; j > -Settings::WORLD_HEIGHT; j -= m_background.height)
		{
			DrawTexture(m_background, i, j, WHITE);
		}
	}
	m_ball.draw();
	m_platform.draw();
}