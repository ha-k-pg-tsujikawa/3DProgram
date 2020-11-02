#include "Enemy.h"


Enemy::Enemy()
{
	SetPos(200, 200);
	speed = 1.5f;
	circle_radius = 100.0f;
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	Vec2 direction = Vec2(pos_player.X - Pos.X, pos_player.Y - Pos.Y);
	Vec2 false_direction = direction;

	float circle_direction = sqrt(direction.X * direction.X + direction.Y * direction.Y);
	
	direction.X /= circle_direction;
	direction.Y /= circle_direction;

	if (circle_direction <= circle_radius)
	{
		if (false_direction.X > 0.5f)Pos.X += direction.X * speed;
		if (false_direction.Y > 0.5f)Pos.Y += direction.Y * speed;
		if (false_direction.X < -0.5)Pos.X += direction.X * speed;
		if (false_direction.Y < -0.5)Pos.Y += direction.Y * speed;
	}
}

void Enemy::Draw()
{
	Engine::DrawTexture(Pos.X, Pos.Y, "Enemy");
}

void Enemy::SetPosPlayer(Vec2 value)
{
	pos_player.X = value.X;
	pos_player.Y = value.Y;
}