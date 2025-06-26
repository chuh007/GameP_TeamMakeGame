#pragma once
#include "Enums.h"
#include "Position.h"
#include "Define.h"

class MapManager
{
private:
	MapManager();
	~MapManager();
public:
	static MapManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new MapManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
	bool CanRanderThisPos(const Position& _pos);
	void SetRanderDir(const Dir& _dir);
	void FovLock();
	void Init();
private:
	static MapManager* m_inst;
	char(*m_curRanderableMap) [MAP_WIDTH];
	// �̰� �迭 ��������
	// (*)�� m_curRanderableMap�� ���������� ���
	// ���⼭ ��ȣ ����, ������ �迭�� �����ϰڴٴ� �Ҹ�.
	// ����Ű�°� �迭��, index�� �迭 ������ �����δ�.
	// 2���� �迭�� ������ �ϳ��� ���� ������ ���ش�.

private:
	int m_fovLevel;
	char m_upMap[MAP_HEIGHT][MAP_WIDTH];
	char m_downMap[MAP_HEIGHT][MAP_WIDTH];
	char m_leftMap[MAP_HEIGHT][MAP_WIDTH];
	char m_rightMap[MAP_HEIGHT][MAP_WIDTH];

	char m_secondupMap[MAP_HEIGHT][MAP_WIDTH];
	char m_seconddownMap[MAP_HEIGHT][MAP_WIDTH];
	char m_secondleftMap[MAP_HEIGHT][MAP_WIDTH];
	char m_secondrightMap[MAP_HEIGHT][MAP_WIDTH];

	char m_threeupMap[MAP_HEIGHT][MAP_WIDTH];
	char m_threedownMap[MAP_HEIGHT][MAP_WIDTH];
	char m_threeleftMap[MAP_HEIGHT][MAP_WIDTH];
	char m_threerightMap[MAP_HEIGHT][MAP_WIDTH];

	char m_fullMap[MAP_HEIGHT][MAP_WIDTH];
};
