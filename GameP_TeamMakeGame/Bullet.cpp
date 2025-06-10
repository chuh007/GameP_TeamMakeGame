#include "Bullet.h"
#include "Console.h"
#include "BulletManager.h"

Bullet::Bullet(Direction myDir, int speed , int lifeSet) : MoveEntity(speed)
{
	const int MOVE_X[4] = { 0,0,-1,1 };
	const int MOVE_Y[4] = { -1,1,0,0 };
	dir = myDir;
	int dirMove = (int)myDir;
	moveX = MOVE_X[dirMove];
	moveY = MOVE_Y[dirMove];
	life = lifeSet;
	BulletManager::GetInst()->Addbullet(this);
}

Bullet::~Bullet()
{
	BulletManager::GetInst()->DeleteBullet(this);
}

void Bullet::Update()
{
	Move();
	life--;
	if (life <= 0)
	{
		isDead = true;
	}
}

void Bullet::Render()
{
	Gotoxy(nowPos->x, nowPos->y);
	cout << "£ª";
}
