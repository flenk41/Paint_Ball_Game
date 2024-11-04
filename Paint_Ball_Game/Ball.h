#pragma once
#include<raylib.h>

class Ball
{
public:
	int x, y;
	int range;
	int speedX, speedY;
	Color color;

	Ball(int StartX, int StartY, int RangeCircl, int SpeedX, int SpeedY, Color cOlor);
	void Draw();
	void Update(int screenWidth, int screenHeight);
	void Reset(int startX, int startY);
};

