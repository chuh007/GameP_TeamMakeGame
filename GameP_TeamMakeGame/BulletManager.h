#pragma once
#include "defines.h"
#include "Bullet.h"
#include <vector>
class BulletManager
{
private:
	BulletManager();
	~BulletManager();
public:
	static BulletManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new BulletManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
	void Addbullet(Bullet* bullet)
	{
		m_bullets.push_back(bullet);
	}
	void DeleteBullet(Bullet* bullet)
	{
		int i;
		for (auto& b : m_bullets)
		{
			if (b == bullet)
			{
				m_bullets.erase(m_bullets.begin() + i);
				break;
			}
			++i;
		}
	}
public:
	const std::vector<Bullet*>& GetBullets()
	{
		return m_bullets;
	}

private:
	static BulletManager* m_inst;
	std::vector<Bullet*> m_bullets;
};

