#pragma once
#include "MoveEntity.h"
#include "Bullet.h"
class Enemy : public MoveEntity
{
public:
	Enemy(Direction myDir, int speed);
	~Enemy();
public:
	const bool CheckFeedback(const Bullet& bullet)const;
	const bool CheckFinded(const Direction playerDir)const;
};