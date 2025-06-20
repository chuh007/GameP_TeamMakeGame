#include "EnemyManager.h"
#include "Enemy.h"
#include "EnemyData.h"
#include "Console.h"
#include <random>

EnemyManager* EnemyManager::m_inst = __nullptr;

EnemyManager::EnemyManager()
{
	srand((unsigned int)time(NULL));
	oldTime = clock();
	currentTime = clock();
	speedMultiply = 1;
	lifeMultiply = 1;
}

void EnemyManager::Update()
{
	currentTime = clock();
	if (currentTime - oldTime >= SPAWN_TIME * 1000)
	{
		oldTime = currentTime;
		Dir dir = (Dir)(rand() % 4);
		new Enemy(dir, speedMultiply, lifeMultiply);
	}
}