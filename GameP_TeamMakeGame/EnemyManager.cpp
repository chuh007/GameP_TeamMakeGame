#include "EnemyManager.h"
#include "Enemy.h"
#include "FasterEnemy.h"
#include "InvisibleEnemy.h"
#include "FlipEnemy.h"
#include "EnemyData.h"
#include "Console.h"
#include <random>

EnemyManager* EnemyManager::m_inst = __nullptr;

EnemyManager::EnemyManager()
{
	srand((unsigned int)time(NULL));
	oldTime = clock();
	currentTime = clock();
	timeMultiply = 1;
	lifeMultiply = 1;
}

void EnemyManager::Update()
{
	currentTime = clock();
	if (currentTime - oldTime >= SPAWN_TIME * 1000)
	{
		oldTime = currentTime;
		Dir dir = (Dir)(rand() % 4);
		int randnum = rand() % 8;
		if (randnum <= 3)
		{
			new Enemy(dir, timeMultiply, lifeMultiply * 3);
		}
		else if (randnum <= 5)
		{
			new FasterEnemy(dir, timeMultiply * 0.025, lifeMultiply);
		}
		else if (randnum <= 6)
		{
			new InvisibleEnemy(dir, timeMultiply * 5, lifeMultiply * 2);
		}
		else
		{
			new FlipEnemy(dir, timeMultiply, lifeMultiply * 2);
		}
	}
}