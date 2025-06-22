#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include <Time.h>


class Enemy : public GameObject
{
public:
	Enemy(Dir myDir, int speed , int lifeSet);
	~Enemy();
public:
	bool CheckFeedback(const Bullet& gameObject);
	bool CheckFinded(const Dir playerDir);
	virtual void Update() override;
	virtual void Render() override;
private:
	bool PlayerFeedback();
	void Move();

protected:
	Dir dir;
	int moveX;
	int moveY;
	int life;

private:
	clock_t oldTime;
	clock_t currentTime;
};