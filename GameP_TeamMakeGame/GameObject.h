#pragma once
#include "Position.h"
#include <iostream>
using std::cout;
using std::string;
class ObjectManager;

class GameObject
{
public:
	GameObject(Position _pos = { 0,0 });
	virtual ~GameObject() = default;
	virtual void Update() abstract;
	virtual void Render() abstract;
public:
	const Position& GetPos() const { return m_pos; }
public:
	bool isDead;
protected:
	Position m_pos;
	string m_renderIcon;
};

