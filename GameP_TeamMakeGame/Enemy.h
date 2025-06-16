#pragma once
#include "MoveEntity.h"
#include "Bullet.h"
class Enemy : public MoveEntity
{
public:
	Enemy(Dir myDir, int speed , int lifeSet);
	~Enemy();
public:
	bool CheckFeedback(const Bullet& bullet);
	bool CheckFinded(const Dir playerDir);
	virtual void Update() override;
	virtual void Render() override;
};