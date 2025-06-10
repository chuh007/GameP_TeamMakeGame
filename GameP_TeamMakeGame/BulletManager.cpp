#include "BulletManager.h"
BulletManager* BulletManager::m_inst = __nullptr;

BulletManager::~BulletManager()
{
	for (auto& e : m_bullets)
	{
		delete e;
	}
}