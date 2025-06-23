#include "EnemyCollisionManager.h"
#include "Enemy.h"

EnemyCollisionManager::EnemyCollisionManager()
{
}

EnemyCollisionManager::~EnemyCollisionManager()
{
}

void EnemyCollisionManager::Add(Enemy* _enemy)
{
	m_enemys.push_back(_enemy);
}

void EnemyCollisionManager::Update()
{
}
