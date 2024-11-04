#include "Ball.h"

Ball::Ball(int StartX, int StartY, int RangeCircl, int SpeedX, int SpeedY, Color cOlor)
	: x(StartX), y(StartY), range(RangeCircl), speedX(SpeedX), speedY(SpeedY), color(cOlor) {
};

void Ball::Draw() {
	DrawCircle(x, y, range, color);
}

void Ball::Update(int screenWidth, int screenHeight) {
	x += speedX;
	y += speedY;

	if (x <= range || x >= screenWidth - range) speedX *= -1;
	if (y <= range || y >= screenHeight - range) speedY *= -1;
}

void Ball::Reset(int startX, int startY)
{
	x = startX;
	y = startY;

	speedX = (speedX > 0) ? -5 : 5;
	speedY = (speedY > 0) ? -5 : 5;
}
