#include "ObjectManager.h"
#include "GameObject.h"
#include "Console.h"
ObjectManager* ObjectManager::m_inst = __nullptr;
ObjectManager::ObjectManager()
{

}
ObjectManager::~ObjectManager()
{
	for (auto& e : m_objects)
	{
		SAFE_DELETE(e);
	}
}

void ObjectManager::Update()
{
    for (int i = 0; i < m_objects.size(); ++i)
    {
        if (m_objects[i]->isDead)
        {
            m_objects[i]->OnDestroy();
            SAFE_DELETE(m_objects[i]);
            m_objects.erase(m_objects.begin() + i);
            continue;
        }

        // 핵심: 이전 좌표 지우기 (잔상 제거)
        m_objects[i]->OnDestroy();

        // 논리 업데이트
        m_objects[i]->Update();

        // 새 좌표 출력
        m_objects[i]->Render();
    }
}


void ObjectManager::AddObject(GameObject* obj)
{
	m_objects.push_back(obj);
}

