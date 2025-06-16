#pragma once
#include "CharacterObject.h"
class Muzzle : public CharacterObject
{
public:
	using Base = CharacterObject;
	Muzzle(Position _pos);
	void Update() override;
	void Render() override;
	void Move(Dir _dir) override;

private:
	Dir m_curDir;
	Position m_playerPos;
};

