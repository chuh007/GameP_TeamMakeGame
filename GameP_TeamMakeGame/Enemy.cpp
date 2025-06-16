#include "Enemy.h"
#include "Console.h"

Enemy::Enemy(Dir myDir, int speed , int lifeSet) : MoveEntity(speed)
{
	const int SPAWN_X[4] = { 0,0,0,0 };
	const int SPAWN_Y[4] = { 0,0,0,0 };
	const int MOVE_X[4] = { 0,0,-1,1 };
	const int MOVE_Y[4] = { -1,1,0,0 };
	dir = myDir;
	int dirMove = (int)myDir;
	nowPos->SetPos(SPAWN_X[dirMove], SPAWN_Y[dirMove]);
	moveX = MOVE_X[dirMove];
	moveY = MOVE_Y[dirMove];
	life = lifeSet;
}

Enemy::~Enemy()
{

}

bool Enemy::CheckFeedback(const Bullet& bullet)
{
	switch (dir)
	{
	//case Dir::UP:
	//	return bullet.dir == Dir::DOWN && nowPos->y <= bullet.nowPos->y;
	//case Dir::DOWN:
	//	return bullet.dir == Dir::UP && nowPos->y >= bullet.nowPos->y;
	//case Dir::LEFT:
	//	return bullet.dir == Dir::RIGHT && nowPos->x <= bullet.nowPos->x;
	//case Dir::RIGHT:
	//	return bullet.dir == Dir::LEFT && nowPos->x >= bullet.nowPos->x;
	//default:
		return false;
	}
}

bool Enemy::CheckFinded(const Dir playerDir)
{
	switch (dir)
	{
	case Dir::UP:
		return playerDir == Dir::DOWN;
	case Dir::DOWN:
		return playerDir == Dir::UP;
	case Dir::LEFT:
		return playerDir == Dir::RIGHT;
	case Dir::RIGHT:
		return playerDir == Dir::LEFT;
	default:
		return false;
	}
}

void Enemy::Update()
{
	Move();
	//for (auto& i : BulletManager::GetInst()->GetBullets())
	//{
	//	if (CheckFeedback(*i))
	//	{
	//		life--;
	//		if (life <= 0)
	//		{
	//			isDead = true;
	//			i->isDead = true;
	//			continue;
	//		}
	//	}
	//}
}

void Enemy::Render()
{
	Gotoxy(nowPos->x, nowPos->y);
	/*if (CheckFinded(Player::dis))
	{
		cout << "¢ß";
	}
	else
	{
		cout << "  ";
	}*/
}
