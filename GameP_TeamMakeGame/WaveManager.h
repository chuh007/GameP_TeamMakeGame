#pragma once
#include "Define.h"
#include <time.h>
class WaveManager
{
private:
	WaveManager();
	~WaveManager();
public:
	void Update();
	static WaveManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new WaveManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
private:
	static WaveManager* m_inst;
	bool m_isBattleMode;
	int m_waveCnt;
	clock_t m_oldTime;
	clock_t m_currentTime;
};

