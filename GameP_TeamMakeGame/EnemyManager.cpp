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
	lifeMultiply = 2;
	FasterPer = 0;
	InvisiblePer = 0;
	FlipPer = 0;
}

void EnemyManager::Update()
{
	currentTime = clock();
	if (currentTime - oldTime >= SPAWN_TIME * 1000)
	{
		oldTime = currentTime;
		Dir dir = (Dir)(rand() % 4);
		int randnum = rand() % 100 + 1;
		if (randnum <= FasterPer)
		{
			new FasterEnemy(dir, timeMultiply * 0.025, 1);
		}
		else if (randnum <= FasterPer + InvisiblePer)
		{
			new InvisibleEnemy(dir, timeMultiply * 5, 2);
		}
		else if(randnum <= FasterPer + InvisiblePer)
		{
			new FlipEnemy(dir, timeMultiply, 2);
		}
		else
		{
			new Enemy(dir, timeMultiply, 1 * lifeMultiply);
		}

	}
}

void EnemyManager::WaveToEnemySet(int Wave)
{
	if (Wave >= 20)
	{
		FasterPer = 20;
		FlipPer = 10;
		InvisiblePer = 5;
		lifeMultiply = 4;
	}
	else if (Wave >= 15)
	{
		FasterPer = 15;
		FlipPer = 7;
		InvisiblePer = 2;
	}
	else if (Wave >= 10)
	{
		FlipPer = 5;
		FasterPer = 12;
		lifeMultiply = 3;
	}
	else if (Wave >= 5)
	{
		FasterPer = 10;
	}
}
