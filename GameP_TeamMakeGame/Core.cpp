#include "Core.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Console.h"
#include "Mci.h"
#include <Windows.h>

void Core::Run()
{
	SetConsoleFont(L"NSimSun", { 20, 20 }, FW_BOLD);
	PlaySoundID(SOUNDID::BGM, true);
	SetConsoleSettings(1000, 650, false, TEXT("2-1 BOMBMAN"));
	SetCursorVisual(true, 50);

	Player p;
	while (true)
	{
		Update();
		Sleep(100);
		// ÇÁ·¹ÀÓ½ÌÅ©
	}
}

void Core::Update()
{
	ObjectManager::GetInst()->Update();
}

