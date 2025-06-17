#pragma once
#include "CharacterObject.h"
#include "Bullet.h"
class Enemy : public CharacterObject
{
public:
	Enemy(Dir myDir, int speed , int lifeSet);
	~Enemy();
public:
	bool CheckFeedback(const Bullet& bullet);
	bool CheckFinded(const Dir playerDir);
	virtual void Update() override;
	virtual void Render() override;
	virtual void Move(Dir _dir) override;

protected:
	Dir dir;
	int moveX;
	int moveY;
	int moveSpeed;
	int life;
};