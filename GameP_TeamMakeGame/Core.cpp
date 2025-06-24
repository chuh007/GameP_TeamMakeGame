#include "Core.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Muzzle.h"
#include "Console.h"
#include "Define.h"
#include "Mci.h"
#include "InputHandler.h"
#include "ICommand.h"
#include "WaveManager.h"
#include "MapManager.h"
#include "TitleManager.h"
#include <Windows.h>
#include <fstream>

Core::Core()
	: m_isRunning(true)
	, m_player(nullptr)
	, m_muzzle(nullptr)
	, m_resoulution()
	, m_inputHandler(nullptr)
	, m_map()
{
	ecurScene = Scene::Title;
	SetConsoleSettings(1000, 650, false, TEXT("GAME"));
	m_resoulution = GetConsoleResolution();
	m_player = new Player({ 12, 12 });
	m_muzzle = new Muzzle({ 12, 12 });
	m_inputHandler = new InputHandler();
	std::ifstream mapFile("map.txt");
	if (mapFile.is_open())
	{
		for (int i = 0; i < MAP_HEIGHT; ++i)
		{
			mapFile >> m_map[i];
		}
		mapFile.close();
	}
	else cout << "실패했다실패했다";
}

Core::~Core()
{
	SAFE_DELETE(m_player);
	SAFE_DELETE(m_muzzle);
	SAFE_DELETE(m_inputHandler);
}

void Core::Run()
{
	Init();

	while (m_isRunning)
	{
		Update();
		FrameSync(60);
	}
}

void Core::Init()
{
	SetCursorVisual(false, 50);
	/*Gotoxy(0, 0);

	for (int i = 0;i < MAP_HEIGHT - 1; ++i)
	{
		for (int j = 0; j < MAP_WIDTH - 1; ++j)
		{
			if (!MapManager::GetInst()
				->CanRanderThisPos({ j,i }))
				cout << "  ";
			else if (m_map[i][j] == '2') cout << "  ";
			else cout << (m_map[i][j] == '0' ? "□" : "■");
		}
		Gotoxy(0, i + 1);
	}*/
}

void Core::Update()
{
	if (ecurScene == Scene::Game)
	{
		ICommand* cmd = m_inputHandler->HandleInput();
		if (cmd)
		{
			cmd->Execute(m_muzzle);
			delete cmd;
		}
		Gotoxy(0, 0);
		for (int i = 0; i < MAP_HEIGHT - 1; ++i)
		{
			for (int j = 0; j < MAP_WIDTH - 1; ++j)
			{
				if (!MapManager::GetInst()
					->CanRanderThisPos({ j,i }))
					cout << "  ";
				else if (m_map[i][j] == '2') cout << "  ";
				else cout << (m_map[i][j] == '0' ? "□" : "■");
			}
			Gotoxy(0, i + 1);
		}
		ObjectManager::GetInst()->Update();
		WaveManager::GetInst()->Update();
	}
	else if (ecurScene != Scene::QUIT)
	{
		Key input = m_inputHandler->TitleInput();
		if (input != Key::NONE)
		{
			TitleManager::GetInst()->Update(input, ecurScene);
		}
		else if (ecurScene == Scene::Title)
		{
			TitleManager::GetInst()->RenderTitle();
		}
	}
	else
	{
		m_isRunning = false;
	}
}

