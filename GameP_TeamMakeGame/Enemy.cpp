#include "Enemy.h"
#include "Console.h"
#include "EnemyData.h"
#include "EnemyCollisionManager.h"

Enemy::Enemy(Dir myDir, int speedMultiply, int lifeMultiply) : GameObject ({ 0, 0 })
{
	EnemyCollisionManager::GetInst()->Add(this);
	dir = myDir;
	oldTime = clock();
	currentTime = clock();
	int dirMove = (int)myDir;
	m_pos = { SPAWN_X[dirMove] , SPAWN_Y[dirMove] };
	moveX = MOVE_X[dirMove];
	moveY = MOVE_Y[dirMove];
	life = LIFE_INIT * lifeMultiply;
	m_renderIcon = "¡Ø";
}

Enemy::~Enemy()
{

}

void Enemy::CheckFeedback(const int& _damage)
{
	life -= _damage;
	if (life <= 0)
	{
		isDead = true;
		EnemyCollisionManager::GetInst()->UpdateEnemyList();
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
	currentTime = clock();
	if (currentTime - oldTime >= MOVE_TIME * 1000)
	{
		oldTime = currentTime;
		Move();
	}
	if (PlayerFeedback())
	{
		isDead = true;
		EnemyCollisionManager::GetInst()->UpdateEnemyList();
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
	GameObject::Render();
	//}
	
}

void Enemy::Move()
{
	m_pos = { m_pos.x + moveX, m_pos.y + moveY };
}
  