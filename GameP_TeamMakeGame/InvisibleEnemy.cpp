#include "InvisibleEnemy.h"
#include "Console.h"

InvisibleEnemy::InvisibleEnemy(Dir myDir, float timeMultiply, int lifeMultiply)
	:Enemy(myDir, timeMultiply, lifeMultiply)
{
}

InvisibleEnemy::~InvisibleEnemy()
{
	Gotoxy(30, 10);
	cout << "  ";
}



void InvisibleEnemy::Render()
{
	SetColor(COLOR::YELLOW);
	Gotoxy(30, 10); //임시로 넣어둔것
	cout << "!";
	SetColor();
}
