#include "GameObject.h"
#include "ObjectManager.h"
GameObject::GameObject()
{
	ObjectManager::GetInst()->AddObject(this);
	isDead = false;
}