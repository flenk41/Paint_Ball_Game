#include<raylib.h>
#include<string>

#include "Player.h"
#include "Ball.h"

int screenWidth = 1200;
int screenHeight = 900;
int scoreLeft = 0;
int scoreRight = 0;
Color background{ 20,22,36,255 };

Player playerOne(0, screenHeight / 2, 10, 100, RED, 10);
Player playerTwo(screenWidth - 10, screenHeight / 2, 10, 100, BLUE, 10);

Ball ball(screenWidth / 2, screenHeight / 2, 20, 5, 3, WHITE);

int main() {
	InitWindow(screenWidth, screenHeight, "PaintBall");
	SetTargetFPS(90);

	while (WindowShouldClose() == false) {
		BeginDrawing();
		ClearBackground(background);

		// Player
		playerOne.Update(IsKeyDown(KEY_W), IsKeyDown(KEY_S), screenHeight);
		playerTwo.Update(IsKeyDown(KEY_UP), IsKeyDown(KEY_DOWN), screenHeight);


		playerOne.Draw();
		playerTwo.Draw();
		// Check Gol
		if (ball.x < 0) {
			scoreRight++;
			ball.Reset(screenWidth / 2, screenHeight / 2);
		}
		if (ball.x > screenWidth) {
			scoreLeft++;
			ball.Reset(screenWidth / 2, screenHeight / 2);
		}
		if (ball.y < 0 || ball.y > screenHeight) {
			ball.speedY *= -1;
		}

		// Collision CheckUP
		if (CheckCollisionCircleRec(Vector2{ (float)ball.x, (float)ball.y }, ball.range, Rectangle{ (float)playerOne.x, (float)playerOne.y, (float)playerOne.width, (float)playerOne.height })) {
			ball.speedX *= -1;
		}
		if (CheckCollisionCircleRec(Vector2{ (float)ball.x, (float)ball.y }, ball.range, Rectangle{ (float)playerTwo.x, (float)playerTwo.y, (float)playerTwo.width, (float)playerTwo.height })) {
			ball.speedX *= -1;
		}
		// Ball
		ball.Update(screenWidth, screenHeight);
		ball.Draw();
		// Score Drow
		std::string scoreText = std::to_string(scoreLeft) + ':' + std::to_string(scoreRight);
		int textWidth = MeasureText(scoreText.c_str(), 40);
		DrawText(scoreText.c_str(), screenWidth / 2 - textWidth / 2, 20, 40, YELLOW);

		EndDrawing();
	}
	CloseWindow();
}