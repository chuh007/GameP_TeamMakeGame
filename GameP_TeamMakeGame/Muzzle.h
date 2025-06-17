#pragma once
#include "CharacterObject.h"
#include "IFireable.h"
class Muzzle : public CharacterObject
	, public IFireable
{
public:
	using Base = CharacterObject;
	Muzzle(Position _pos);
	void Update() override;
	void Render() override;
	void Move(Dir _dir) override;
	void Fire();

private:
	Dir m_curDir;
	Position m_playerPos;
};

