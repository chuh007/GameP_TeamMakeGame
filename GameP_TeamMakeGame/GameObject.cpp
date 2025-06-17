#include "GameObject.h"
#include "ObjectManager.h"
#include "Console.h"


GameObject::GameObject(Position _pos)
	: m_pos({ 0,0 })
	, isDead(false)
{
	ObjectManager::GetInst()->AddObject(this);
}

GameObject::~GameObject()
{
	isDead = true;
}

void GameObject::Update()
{
}

void GameObject::Render()
{
	if (m_isranderable)
	{
		Gotoxy(m_pos.x, m_pos.y);
		cout << m_renderIcon;
	}
}
