#pragma once
#include "defines.h"
#include "GameObject.h"
#include <vector>
class ObjectManager
{
private:
	ObjectManager();
	~ObjectManager();
public:
	static ObjectManager* GetInst()
	{
		if (m_inst == nullptr)
			m_inst = new ObjectManager;
		return m_inst;
	}
	static void DestoryInst()
	{
		SAFE_DELETE(m_inst);
	}
	void Update()
	{
		for (int i = 0;i < m_objects.size();++i)
		{
			if (m_objects[i]->isDead)
			{
				delete m_objects[i];
				m_objects.erase(m_objects.begin() + i);
				continue;
			}
			m_objects[i]->Update();
			m_objects[i]->Render();
		}
	}
	void AddObject(GameObject* obj)
	{
		m_objects.push_back(obj);
	}
private:
	static ObjectManager* m_inst;
	std::vector<GameObject*> m_objects;
};

