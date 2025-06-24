#include "FlipEnemy.h"
#include "EnemyData.h"
#include "Console.h"
#include "MapManager.h"

FlipEnemy::FlipEnemy(Dir myDir, float timeMultiply, int lifeMultiply) : Enemy(myDir, timeMultiply, lifeMultiply)
{
	flipPos = { 0,0 };
	dirMove = (int)myDir;
	m_renderIcon = "£¦";
}

void FlipEnemy::Update()
{
	Enemy::Update();
	FlipNowPos();
}

void FlipEnemy::Render()
{
	if (MapManager::GetInst()
		->CanRanderThisPos(flipPos))
	{
		Gotoxy(flipPos.x, flipPos.y);
		cout << m_renderIcon;
	}
}

void FlipEnemy::FlipNowPos()
{
	Position playerPos = PLAYER_POS;

	int flipX = 2 * playerPos.x - m_pos.x;
	int flipY = 2 * playerPos.y - m_pos.y;
	flipPos = {flipX , flipY };
}


