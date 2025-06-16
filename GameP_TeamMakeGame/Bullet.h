#pragma once
#include "CharacterObject.h"
#include <vector>
class Bullet : public CharacterObject
{
public:
	Bullet(Dir myDir, int speed , int lifeSet);
	~Bullet();
public:
	virtual void Update() override;
	virtual void Render() override;

private:
	Dir m_dir;
};