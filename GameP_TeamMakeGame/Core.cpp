#include "Core.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Muzzle.h"
#include "Console.h"
#include "Define.h"
#include "Mci.h"
#include "InputHandler.h"
#include "ICommand.h"
#include "EnemyManager.h"
#include <Windows.h>

Core::Core()
	: m_isRunning(true)
	, m_player(nullptr)
	, m_muzzle(nullptr)
	, m_resoulution()
	, m_inputHandler(nullptr)
{
	SetConsoleSettings(1000, 650, false, TEXT("GAME"));
	m_resoulution = GetConsoleResolution();
	m_player = new Player({ m_resoulution.x / 2, m_resoulution.y / 2 });
	m_muzzle = new Muzzle({ m_resoulution.x / 2, m_resoulution.y / 2 });
	m_inputHandler = new InputHandler();
}

Core::~Core()
{
	SAFE_DELETE(m_muzzle);
	SAFE_DELETE(m_inputHandler);
}

void Core::Run()
{
	Init();

	while (true)
	{
		Update();
		FrameSync(60);
	}
}

void Core::Init()
{
	PlaySoundID(SOUNDID::BGM, true);
	SetCursorVisual(true, 50);
}

void Core::Update()
{
	ICommand* cmd = m_inputHandler->HandleInput();
	if (cmd)
	{
		cmd->Execute(m_muzzle);
		delete cmd; // 호출한 core가 delete를 해야 누수가 안남.
	}
	ObjectManager::GetInst()->Update();
	EnemyManager::GetInst()->Update();
}


