#pragma once
#include "Define.h"
#include "Player.h"
#include <time.h>
class GameManager
{
private:
	GameManager();
	~GameManager();
public:
	void Update();
	static GameManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new GameManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
	void CheckGameOver();
private:
	static GameManager* m_inst;
	bool m_isBattleMode;
	int m_waveCnt;
	clock_t m_oldTime;
	clock_t m_currentTime;
};

