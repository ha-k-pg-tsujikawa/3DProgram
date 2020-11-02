#include "Player.h"


Player::Player()
{
	Speed = 2.0f;
	SetPos(100, 100);
}

Player::~Player()
{

}

void Player::Draw()
{
	Engine::DrawTexture(Pos.X, Pos.Y, "Player");
}

void Player::Update()
{
	if (Engine::IsKeyboardKeyHeld(DIK_UPARROW))
	{
		if (Pos.Y >= 0)Pos.Y -= Speed;
	}
	else if (Engine::IsKeyboardKeyHeld(DIK_DOWNARROW))
	{
		if (Pos.Y <= 450)Pos.Y += Speed;
	}

	if (Engine::IsKeyboardKeyHeld(DIK_RIGHTARROW))
	{
		if(Pos.X <= 620)Pos.X += Speed;
	}
	else if (Engine::IsKeyboardKeyHeld(DIK_LEFTARROW))
	{
		if(Pos.X >= 0)Pos.X -= Speed;
	}
}