#pragma once
#include"Enums.h"
#include "Define.h"
#include "Position.h"


class TitleManager
{
public:
	TitleManager();

public:
	static TitleManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new TitleManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
private:
	static TitleManager* m_inst;
public:
	void Update(Key key , Scene& curScene);
	Menu GetTitleState() { return eMenu; }
public:
	void RenderTitle();
	void RenderInfo();
private:
	Menu eMenu;
	Position resolution;
};

