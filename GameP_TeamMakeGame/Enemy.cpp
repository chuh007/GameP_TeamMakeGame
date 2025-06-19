#include "Enemy.h"
#include "Console.h"
#include "EnemyData.h"

Enemy::Enemy(Dir myDir, int speedMultiply, int lifeMultiply) : GameObject ({ 0, 0 })
{
	dir = myDir;
	int dirMove = (int)myDir;
	moveSpeed = MOVE_SPEED * speedMultiply;
	m_pos = { SPAWN_X[dirMove] , SPAWN_Y[dirMove] };
	moveX = MOVE_X[dirMove] * moveSpeed;
	moveY = MOVE_Y[dirMove] * moveSpeed;
	life = LIFE_INIT * lifeMultiply;
}

Enemy::~Enemy()
{

}

bool Enemy::CheckFeedback(const Bullet& bullet)
{
	switch (dir)
	{
	//case Dir::UP:
	//	return bullet.dir == Dir::DOWN && nowPos->y <= bullet.GetPos()->y;
	//case Dir::DOWN:
	//	return bullet.dir == Dir::UP && nowPos->y >= bullet.GetPos()->y;
	//case Dir::LEFT:
	//	return bullet.dir == Dir::RIGHT && nowPos->x <= bullet.GetPos()->x;
	//case Dir::RIGHT:
	//	return bullet.dir == Dir::LEFT && nowPos->x >= bullet.GetPos()->x;
	//default:
		return false;
	}
}

bool Enemy::PlayerFeedback()
{
	switch (dir)
	{
		case Dir::UP:
			return  m_pos.y <= PLAYER_POS.y;
		case Dir::DOWN:
			return  m_pos.y >= PLAYER_POS.y;
		case Dir::LEFT:
			return  m_pos.x <= PLAYER_POS.x;
		case Dir::RIGHT:
			return  m_pos.x >= PLAYER_POS.x;
		default:
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
	if (PlayerFeedback())
	{
		isDead = true;
		//GameOver
	}
	//for (auto& i : BulletManager::GetInst()->GetBullets())
	//{
	//	if (CheckFeedback(*i))
	//	{
	//		life--;
	//		i->isDead = true;
	//		if (life <= 0)
	//		{
	//			isDead = true;
	//			continue;
	//		}
	//	}
	//}
}

void Enemy::Render()
{
	//if (CheckFinded())
	//{
		Gotoxy(m_pos.x, m_pos.y);
		SetColor(COLOR::WHITE, COLOR::YELLOW);
		cout << "¡Ø";
		SetColor();
	//}
	
}

void Enemy::Move()
{
	m_pos = { m_pos.x + moveX, m_pos.y + (moveY / 2) };
}
