#include "Bullet.h"

Bullet::Bullet(Direction myDir, int speed) : MoveEntity(speed)
{
	const int MOVE_X[4] = { 0,0,-1,1 };
	const int MOVE_Y[4] = { -1,1,0,0 };
	dir = myDir;
	int dirMove = (int)myDir;
	moveX = MOVE_X[dirMove];
	moveY = MOVE_Y[dirMove];
}

Bullet::~Bullet()
{
}