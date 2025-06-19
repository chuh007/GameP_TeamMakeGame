#include "MapManager.h"
#include <fstream>

MapManager* MapManager::m_inst = __nullptr;
MapManager::MapManager()
	: m_upMap()
	, m_downMap()
	, m_leftMap()
	, m_rightMap()
{
	std::ifstream mapFile1("randerup.txt");
	if (mapFile1.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile1 >> m_upMap[i];
		}
		mapFile1.close();
	}
	std::ifstream mapFile2("randerdown.txt");
	if (mapFile2.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile2 >> m_downMap[i];
		}
		mapFile2.close();
	}
	std::ifstream mapFile3("randerleft.txt");
	if (mapFile3.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile3 >> m_leftMap[i];
		}
		mapFile3.close();
	}
	std::ifstream mapFile4("randerright.txt");
	if (mapFile4.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile4 >> m_rightMap[i];
		}
		mapFile4.close();
	}
	m_curRanderableMap = m_upMap;
}

MapManager::~MapManager()
{
}

bool MapManager::CanRanderThisPos(Position _pos)
{
	return m_curRanderableMap[_pos.y][_pos.x] == '1';
}

void MapManager::SetRanderDir(Dir _dir)
{
	switch (_dir)
	{
	case Dir::UP:
		m_curRanderableMap = m_upMap;
		break;
	case Dir::DOWN:
		m_curRanderableMap = m_downMap;
		break;
	case Dir::LEFT:
		m_curRanderableMap = m_leftMap;
		break;
	case Dir::RIGHT:
		m_curRanderableMap = m_rightMap;
		break;
	}
}
