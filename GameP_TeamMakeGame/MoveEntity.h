#pragma once
#include "Enums.h"
#include "Pos.h"
#include "GameObject.h"

class MoveEntity : public GameObject
{
public:
	MoveEntity(int setSpeed);
	~MoveEntity();
public:
	void Move();
public:
	PPOS nowPos;
	Dir dir;
protected:
	int moveX;
	int moveY;
	int moveSpeed;
	int life;
};

