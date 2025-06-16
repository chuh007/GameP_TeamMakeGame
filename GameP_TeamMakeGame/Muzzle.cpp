#include "Muzzle.h"
#include "Console.h"

Muzzle::Muzzle(Position _pos)
	:m_curDir(Dir::UP)
	, m_playerPos()
{
	m_renderIcon = "¡ã";
	m_pos = { _pos.x , _pos.y - 1 };
}

void Muzzle::Update()
{
}

void Muzzle::Render()
{
	Base::Render();
	Gotoxy(m_pos.x, m_pos.y);
	cout << m_renderIcon;
}

void Muzzle::Move(Dir _dir)
{
	switch (_dir)
	{
	case Dir::UP:
		m_renderIcon = "¡ã";
		--m_pos.y;
		break;
	case Dir::DOWN:
		m_renderIcon = "¡å";
		++m_pos.y;
		break;
	case Dir::LEFT:
		m_renderIcon = "¢¸";
		--m_pos.x;
		break;
	case Dir::RIGHT:
		m_renderIcon = "¢º";
		++m_pos.x;
		break;
	}
}
