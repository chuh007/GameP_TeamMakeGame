#pragma once
#include "Define.h"
#include "Bullet.h"
#include <vector>

class Enemy;

class EnemyCollisionManager
{
private:
	EnemyCollisionManager();
	~EnemyCollisionManager();
public:
	static EnemyCollisionManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new EnemyCollisionManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
	void Add(Enemy* _enemy);
	void CheckCollision(Bullet* _bullet);
	void UpdateEnemyList();
private:
	static EnemyCollisionManager* m_inst;
	std::vector<Enemy*> m_enemys;
};

