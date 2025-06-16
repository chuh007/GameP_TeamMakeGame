#include "Player.h"
#include "Console.h"

Player::Player(Position _pos)
{
	m_renderIcon = "¡×";
	m_pos = _pos;
}

void Player::Update()
{

}

void Player::Render()
{
	Base::Render();
	Gotoxy(m_pos.x, m_pos.y);
	cout << "¡×";
}

void Player::Move(Dir _dir)
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
