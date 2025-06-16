#include "ObjectManager.h"
#include "GameObject.h"
ObjectManager* ObjectManager::m_inst = __nullptr;
ObjectManager::ObjectManager()
{

}
ObjectManager::~ObjectManager()
{
	for (auto& e : m_objects)
	{
		delete e;
	}
}

void ObjectManager::Update()
{
	for (int i = 0;i < m_objects.size();++i)
	{
		if (m_objects[i]->isDead)
		{
			SAFE_DELETE(m_objects[i]);
			m_objects.erase(m_objects.begin() + i);
			continue;
		}
		m_objects[i]->Update();
		m_objects[i]->Render();
	}
}


void ObjectManager::AddObject(GameObject* obj)
{
	m_objects.push_back(obj);
}

