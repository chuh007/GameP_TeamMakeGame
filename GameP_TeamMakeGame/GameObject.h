#pragma once
#include "ObjectManager.h"
class GameObject
{
private:
	GameObject()
	{
		ObjectManager::GetInst()->AddObject(this);
	};
public:
	virtual void Update() abstract
	{

	}
	virtual void Render() abstract
	{

	}

public:
	bool isDead;
};

