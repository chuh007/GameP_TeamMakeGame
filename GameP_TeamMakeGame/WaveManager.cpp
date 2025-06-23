#include "WaveManager.h"
#include "EnemyManager.h"
WaveManager* WaveManager::m_inst = nullptr;
WaveManager::WaveManager()
	:m_isBattleMode(true)
	,m_oldTime(clock())
	,m_currentTime(clock())
{
}

WaveManager::~WaveManager()
{

}

void WaveManager::Update()
{
	if(m_isBattleMode)
		EnemyManager::GetInst()->Update();
}
