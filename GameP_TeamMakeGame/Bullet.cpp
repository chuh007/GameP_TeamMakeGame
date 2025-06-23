#include "Bullet.h"
#include "Console.h"


Bullet::Bullet(Position _pos,
	Dir _dir,
	int _lifeTick,
	int _damage)
	: CharacterObject(_pos)
	, m_dir(_dir)
	, lifetick(_lifeTick)
	, damage(_damage)
{
	m_renderIcon = "*";
	m_isranderable = true;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	Base::Update();
	Move(m_dir);
	lifetick--;
	if (lifetick <= 0) isDead = true;
}

void Bullet::Render()
{
	Base::Render();
}

void Bullet::Move(Dir _dir)
{
	switch (_dir)
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

void Bullet::GetDamage()
{
}
