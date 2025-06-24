#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <Time.h>


class Enemy : public GameObject
{
public:
	Enemy(Dir myDir, float speed , int lifeSet);
	~Enemy();
public:
	void CheckFeedback(const int& _damage);
	bool CheckFinded(const Dir playerDir);
	virtual void Update() override;
	virtual void Render() override;
protected:
	bool PlayerFeedback();
	void Move();

protected:
	Dir dir;
	int moveX;
	int moveY;
	int life;
	clock_t oldTime;
	clock_t currentTime;
	float time;
};