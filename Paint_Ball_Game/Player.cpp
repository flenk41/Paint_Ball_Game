#include "Player.h"

Player::Player(int startX, int startY, int w, int h, Color col, int spd)
	: x(startX), y(startY), width(w), height(h), speed(spd), color(col) {
};

void Player::Draw() {
	DrawRectangle(x, y, width, height, color);
}

void Player::Update(bool moveUpKey, bool moveDownKey, int screenHeight) {
	if (moveUpKey && y > 0) y -= speed;
	if (moveDownKey && y + height < screenHeight) y += speed;
}