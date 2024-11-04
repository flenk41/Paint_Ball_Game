#pragma once
#include <raylib.h>

class Player
{
public:
	int x, y, speed;
	int width, height;
	Color color;
	Player(int startX, int startY, int w, int h, Color col, int spd);
	void Draw();
	void Update(bool moveUpKey, bool moveDownKey, int screenHeight);
};

