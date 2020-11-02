#include "Base.h"


Base::Base()
{
	Pos.X = 0.0f;
	Pos.Y = 0.0f;
}

Base::~Base()
{
	
}


void Base::SetPos(float x, float y)
{
	Pos.X = x;
	Pos.Y = y;
}

Vec2 Base::GetPos()
{
	return Pos;
}
