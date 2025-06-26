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
	lifePer = 1;
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
			new InvisibleEnemy(dir, timeMultiply * 5, SetHp(10, lifePer));
		}
		else if(randnum <= FasterPer + InvisiblePer + FlipPer)
		{
			new FlipEnemy(dir, timeMultiply, SetHp(10, lifePer));
		}
		else
		{
			new Enemy(dir, timeMultiply, SetHp(10 , lifePer));
		}

	}
}

int EnemyManager::SetHp(int baseHp, float hpPer)
{
	return (int)(baseHp * hpPer);
}

void EnemyManager::WaveToEnemySet(int Wave)
{
	lifePer = max(1.0f, pow(1.15f, Wave / 5));
	if (Wave >= 20)
	{
		FasterPer = 20;
		FlipPer = 10;
		InvisiblePer = 5;
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
	}
	else if (Wave >= 5)
	{
		FasterPer = 10;
	}
	else
	{
		FasterPer = 0;
		InvisiblePer = 0;
		FlipPer = 0;
	}
}
