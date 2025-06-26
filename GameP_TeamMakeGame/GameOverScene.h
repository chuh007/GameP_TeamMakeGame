#pragma once
#include"Position.h"
#include"Scene.h"
#include "InputHandler.h"
#include "string"


class GameOverScene : public Scene
{
public:
	GameOverScene();
	~GameOverScene();

public:
	virtual void Init() override;
	virtual void Update() override;
private:
	void Render();
	std::string GetWaveString();
	std::string GetAccuracyString();

private:
	Position resolution;
	InputHandler* m_inputHandler;
};

