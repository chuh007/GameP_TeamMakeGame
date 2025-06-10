#pragma once
#include "MoveEntity.h"
#include <vector>
class Bullet : public MoveEntity
{
public:
	Bullet(Direction myDir, int speed , int lifeSet);
	~Bullet();
public:
	virtual void Update() override;
	virtual void Render() override;
};