#pragma once
#include"Scene.h"
#include "InputHandler.h"
#include "GameObject.h"
#include "Define.h"

class GameScene : public Scene
{
public:
	GameScene();
	~GameScene();
public:
	virtual void Init() override;
	virtual void Update() override;
private:
	GameObject* m_player;
	GameObject* m_muzzle;
	InputHandler* m_inputHandler;
	char m_map[MAP_HEIGHT][MAP_WIDTH];
};