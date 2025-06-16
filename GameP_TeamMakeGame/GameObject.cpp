#include "GameObject.h"
#include "ObjectManager.h"


GameObject::GameObject(Position _pos)
	: m_pos({ 0,0 })
	, isDead(false)
{
	ObjectManager::GetInst()->AddObject(this);
}
