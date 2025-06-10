#pragma once
#include "Enums.h"
#include "Pos.h"

class MoveEntity // : public GameObject
{
public:
	MoveEntity(int setSpeed);
	~MoveEntity();
public:
	void Move();
public:
	PPOS nowPos;
	Direction dir;
protected:
	int moveX;
	int moveY;
	int moveSpeed;
};

