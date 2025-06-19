#pragma once

#include "Console.h"
#include "Define.h"
#include "GameObject.h"
#include "ICommand.h"


class GameObject;
class InputHandler;

class Core
{
public:
	Core();
	~Core();
public:
	void Run();
private:
	void Init();
	void Update();
private:
	bool m_isRunning;
	GameObject* m_player;
	GameObject* m_muzzle;
	InputHandler* m_inputHandler;
	Position m_resoulution;
	char m_map[MAP_HEIGHT][MAP_WIDTH];
};
