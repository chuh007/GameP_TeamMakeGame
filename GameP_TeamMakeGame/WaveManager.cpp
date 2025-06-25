#include "WaveManager.h"
#include "EnemyManager.h"
#include "UpgradeManager.h"
#include "MapManager.h"
#include "UIManager.h"
WaveManager* WaveManager::m_inst = nullptr;
WaveManager::WaveManager()
	:m_isBattleMode(true)
	,m_oldTime(clock())
	,m_currentTime(clock())
	,m_waveCnt(1)
{
	UIManager::GetInst()
		->UpdateUI(UIType::WAVECNT,
			std::to_string(m_waveCnt));
}

WaveManager::~WaveManager()
{

}

void WaveManager::Update()
{
	m_currentTime = clock();
	float time = float(m_currentTime - m_oldTime) / CLOCKS_PER_SEC;

	if (m_isBattleMode && time >= 20.f)
	{
		m_isBattleMode = false;
		UpgradeManager::GetInst()->PlusUpgradeCount();
		UIManager::GetInst()
			->UpdateUI(UIType::MODETXT,"���� ����");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE1, "1. ���ݷ� ����");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE2, "2. ���� ���� ����");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE3, "3. ��ȣ�� ȹ��");
		m_oldTime = m_currentTime;
	}
	else if (!m_isBattleMode && time >= 5.f)
	{
		m_isBattleMode = true;
		m_waveCnt++;
		EnemyManager::GetInst()->WaveToEnemySet(m_waveCnt);
		if (m_waveCnt % 5 == 0)
			MapManager::GetInst()->FovLock();
		UIManager::GetInst()
			->UpdateUI(UIType::WAVECNT,
				std::to_string(m_waveCnt));
		UIManager::GetInst()
			->UpdateUI(UIType::MODETXT, "!����!  ");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE1, "                ");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE2, "                ");
		UIManager::GetInst()
			->UpdateUI(UIType::CHOICE3, "                ");
		m_oldTime = m_currentTime;
	}
	if(m_isBattleMode)
		EnemyManager::GetInst()->Update();
}
