#pragma once
#include "GameObject.h"
class Player : public GameObject
{
public:
	using Base = GameObject;
	Player();
	void Update() override;
	void Render() override;

};

