#pragma once
#include "CharacterObject.h"
#include "Bullet.h"
#include <Time.h>


class Enemy : public CharacterObject
{
public:
	Enemy(Dir myDir, float speed, int lifeSet);
public:
	void CheckFeedback(const int& _damage);
	bool CheckFinded(const Dir playerDir);
	virtual void Update() override;
	virtual void Render() override;
	void Move(Dir _dir) override;
protected:
	bool PlayerFeedback();
	void Hit();
	void DeadBlink();
protected:
	Dir dir;
	int moveX;
	int moveY;
	int life;
	clock_t oldTime;
	clock_t currentTime;
	float time;
};