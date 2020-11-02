#ifndef ENEMY_H
#define ENEMY_H

#include "Base.h"

class Enemy : public Base
{
public:
	Enemy();
	virtual ~Enemy();

	virtual void Update();
	virtual void Draw();

	void SetPosPlayer(Vec2 value);

protected:
	Vec2 pos_player;

private:
	float speed;
	float circle_radius;
};

#endif // !ENEMY_H
