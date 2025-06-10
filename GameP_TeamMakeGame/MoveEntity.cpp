#include "MoveEntity.h"

MoveEntity::MoveEntity(int setSpeed)
{
	nowPos = new POS();
	moveSpeed = setSpeed;
}

MoveEntity::~MoveEntity()
{
	delete nowPos;
}

void MoveEntity::Move()
{
	nowPos->PlusXY(moveX * moveSpeed, moveY * moveSpeed);
}
