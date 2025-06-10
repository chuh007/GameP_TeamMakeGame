#pragma once
#include "Pos.h"
#include <iostream>
using std::cout;
class ObjectManager;

class GameObject
{
public:
	GameObject();
	virtual void Update()
	{

	}
	virtual void Render()
	{

	}

public:
	bool isDead;
	POS curPos;
};

