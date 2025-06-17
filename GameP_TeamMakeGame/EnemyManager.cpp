#include "EnemyManager.h"
#include "Enemy.h"
#include "EnemyData.h"
#include <time.h>
#include <random>

EnemyManager* EnemyManager::m_inst = __nullptr;

EnemyManager::EnemyManager()
{
	EnemySpawnTime = SPAWNTIME;
	srand((unsigned int)time(NULL));
	oldTime = clock() / CLOCKS_PER_SEC;
	currentTime = 0;
	speedMultiply = 1;
	lifeMultiply = 1;
}

void EnemyManager::Update()
{
	currentTime = clock() / CLOCKS_PER_SEC;
	if (currentTime - oldTime >= EnemySpawnTime)
	{
		oldTime = currentTime;
		Dir dir = (Dir)(rand() % 4);
		new Enemy(dir, speedMultiply, lifeMultiply);
	}
}