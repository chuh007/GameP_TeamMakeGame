#include "UpgradeManager.h"

UpgradeManager* UpgradeManager::m_inst = nullptr;
UpgradeManager::UpgradeManager()
	: m_isbarrier(false)
	, m_firedelay(20)
	, m_damage(10)
	, m_CanupgradeCount(0)
{
}

UpgradeManager::~UpgradeManager()
{
}

bool UpgradeManager::CanUpgrade()
{
	return m_CanupgradeCount > 0;
}

void UpgradeManager::Upgrade(Key _key)
{
	m_CanupgradeCount--;
	switch (_key)
	{
	case Key::UPGRADE1:
		m_damage++;
		break;
	case Key::UPGRADE2:
		if (m_firedelay > 0) m_firedelay--;
		break;
	case Key::UPGRADE3:
		m_isbarrier = true;
		break;
	}
}

bool UpgradeManager::GetBarrier()
{
	return m_isbarrier;
}

int UpgradeManager::GetFireDelay()
{
	return m_firedelay;
}

int UpgradeManager::GetDamage()
{
	return m_damage;
}

void UpgradeManager::PlusUpgradeCount()
{
	m_CanupgradeCount++;
}
