#include "Muzzle.h"
#include "Console.h"
#include "Bullet.h"

Muzzle::Muzzle(Position _pos)
	:m_curDir(Dir::UP)
	, m_playerPos(_pos)
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

}

void Muzzle::Move(Dir _dir)
{
	switch (_dir)
	{
	case Dir::UP:
		m_renderIcon = "¡ã";
		m_pos = { m_playerPos.x, 
			m_playerPos.y - 1 };
		break;
	case Dir::DOWN:
		m_renderIcon = "¡å";
		m_pos = { m_playerPos.x,
	m_playerPos.y + 1 };
		break;
	case Dir::LEFT:
		m_renderIcon = "¢¸";
		m_pos = { m_playerPos.x - 2,
m_playerPos.y };
		break;
	case Dir::RIGHT:
		m_renderIcon = "¢º";
		m_pos = { m_playerPos.x + 2,
m_playerPos.y };
		break;
	}
}

void Muzzle::Fire()
{
	new Bullet(m_curDir, 1, 100, 1);
}
