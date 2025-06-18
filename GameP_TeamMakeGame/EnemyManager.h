#pragma once
#include "Enums.h"
#include "defines.h"
#include "Position.h"

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
private:
	static EnemyManager* m_inst;
private:
	float oldTime;
	float currentTime;
	int speedMultiply;
	int lifeMultiply;
};