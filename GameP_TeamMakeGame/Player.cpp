#include "Player.h"
#include "Console.h"

Player::Player(const Position& _pos)
{
	m_renderIcon = "¡×";
	m_pos = _pos;
	m_isranderable = true;
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
