#include "CharacterObject.h"
#include "Console.h"
CharacterObject::CharacterObject(Position _pos)
	:GameObject(_pos)
{
}

void CharacterObject::Update()
{
}

void CharacterObject::Render()
{
	Gotoxy(m_pos.x, m_pos.y);
}

