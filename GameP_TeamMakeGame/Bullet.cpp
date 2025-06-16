#include "Bullet.h"
#include "Console.h"


Bullet::Bullet(Dir myDir, int speed , int lifeSet)
	: CharacterObject()
{
	
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{

}

void Bullet::Render()
{
	Gotoxy(m_pos.x, m_pos.y);
	cout << "£ª";
}
