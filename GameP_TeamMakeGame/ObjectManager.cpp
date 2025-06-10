#include "ObjectManager.h"
ObjectManager* ObjectManager::m_inst = __nullptr;

ObjectManager::~ObjectManager()
{
	for (auto& e : m_objects)
	{
		delete e;
	}
}

