#pragma once
#include "Enums.h"
#include "defines.h"
#include "Position.h"
#include <time.h>

class EnemyManager
{
public:
	EnemyManager();
public:
	static EnemyManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new EnemyManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
public:
	void Update();
	void SetEnemySpeedMultiply(int SpeedMultiply) { speedMultiply = SpeedMultiply; }
	void SetEnemyLifeMultiply(int LifeMultiply) { lifeMultiply = LifeMultiply; }
	float GetCurrntTime() { return currentTime; }
private:
	static EnemyManager* m_inst;
private:
	clock_t oldTime;
	clock_t currentTime;
	int speedMultiply;
	int lifeMultiply;
};