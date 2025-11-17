#include <iostream>
#include <raylib.h>
#include "Ball.h"
#include "Settings.h"
#include "Platform.h"
#include "Game.h"

int main()
{
	InitWindow(Settings::WINDOW_WIDTH, Settings::WINDOW_HEIGHT, "Bouncing Ball");

	Game game{};

	while (!WindowShouldClose())
	{
		game.update();

		BeginDrawing();
		BeginMode2D(game.getCamera());
		ClearBackground(BLACK);
		game.draw();

		EndMode2D();
		EndDrawing();
	}

	CloseWindow();
	return 0;
}