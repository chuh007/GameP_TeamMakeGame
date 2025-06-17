#pragma once
#include "CharacterObject.h"
#include <vector>
class Bullet : public CharacterObject
{
public:
	Bullet(Dir _dir, int _speed , int _lifeTick, int _damage);
	~Bullet();
public:
	virtual void Update() override;
	virtual void Render() override;
	void Move(Dir _dir) override;
	void GetDamage();
private:
	Dir m_dir;
	int lifetick;
	int damage;
};