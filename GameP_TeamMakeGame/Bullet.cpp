#include "Bullet.h"
#include "Console.h"


Bullet::Bullet(Dir _dir,
	int _speed, 
	int _lifeTick,
	int _damage)
	: CharacterObject()
	, m_dir(_dir)
	, lifetick(_lifeTick)
	, damage(_damage)
{
	m_renderIcon = "*";
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	switch (m_dir)
	{
	case Dir::UP:
		--m_pos.y;
		break;
	case Dir::DOWN:
		++m_pos.y;
		break;
	case Dir::LEFT:
		--m_pos.x;
		break;
	case Dir::RIGHT:
		++m_pos.x;
		break;
	}
}

void Bullet::Render()
{
	Gotoxy(m_pos.x, m_pos.y);
	cout << m_renderIcon;
}

void Bullet::Move(Dir _dir)
{
	
}

void Bullet::GetDamage()
{
}
