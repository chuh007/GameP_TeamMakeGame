#pragma once
#include "MoveEntity.h"
class Bullet : public MoveEntity
{
public:
	Bullet(Direction myDir, int speed);
	~Bullet();
};