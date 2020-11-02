#ifndef PLAYER_H
#define PLAYER_H

#include "Base.h"

class Player : public Base
{
public:
	Player();
	virtual ~Player();

	virtual void Update();
	virtual void Draw();

private:
	float Speed;
};

#endif // !PLAYER_H
