#ifndef BASE_H
#define BASE_H

#include "Src/Common/Vec.h"
#include "Src/Engine/Engine.h"

class Base
{
public:
	Base();
	~Base();

	virtual void Update() = 0;
	virtual void Draw() = 0;

	void SetPos(float x, float y);

	Vec2 GetPos();

protected:
	Vec2 Pos;
};

#endif // !BASE_H
