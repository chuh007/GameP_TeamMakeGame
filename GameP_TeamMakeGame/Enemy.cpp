#include "Enemy.h"
#include "Console.h"
#include "BulletManager.h"

Enemy::Enemy(Direction myDir, int speed , int lifeSet) : MoveEntity(speed)
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
	case Direction::UP:
		return bullet.dir == Direction::DOWN && nowPos->y <= bullet.nowPos->y;
	case Direction::DOWN:
		return bullet.dir == Direction::UP && nowPos->y >= bullet.nowPos->y;
	case Direction::LEFT:
		return bullet.dir == Direction::RIGHT && nowPos->x <= bullet.nowPos->x;
	case Direction::RIGHT:
		return bullet.dir == Direction::LEFT && nowPos->x >= bullet.nowPos->x;
	default:
		return false;
	}
}

bool Enemy::CheckFinded(const Direction playerDir)
{
	switch (dir)
	{
	case Direction::UP:
		return playerDir == Direction::DOWN;
	case Direction::DOWN:
		return playerDir == Direction::UP;
	case Direction::LEFT:
		return playerDir == Direction::RIGHT;
	case Direction::RIGHT:
		return playerDir == Direction::LEFT;
	default:
		return false;
	}
}

void Enemy::Update()
{
	Move();
	for (auto& i : BulletManager::GetInst()->GetBullets())
	{
		if (CheckFeedback(*i))
		{
			life--;
			if (life <= 0)
			{
				isDead = true;
				i->isDead = true;
				continue;
			}
		}
	}
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
