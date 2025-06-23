#include<io.h>
#include "TitleManager.h"
#include "Console.h"
#include "Position.h"

TitleManager* TitleManager::m_inst = __nullptr;

TitleManager::TitleManager()
	:eMenu(Menu::FAIL)
{
	eMenu = Menu::START;
}

void TitleManager::Update(Key key)
{
	

	Render();
}

void TitleManager::Render()
{
	Position resolution = GetConsoleResolution();
	int y = resolution.y / 3;
	IsGotoxy(0, y);
	int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L" \t \t ██╗     ██╗ ██████╗ ██╗  ██╗████████╗    ██╗  ██╗███████╗██████╗  ██████╗  " << '\n';
	wcout << L" \t \t ██║     ██║██╔════╝ ██║  ██║╚══██╔══╝    ██║  ██║██╔════╝██╔══██╗██╔═══██╗ " << '\n';
	wcout << L" \t \t ██║     ██║██║  ███╗███████║   ██║       ███████║█████╗  ██████╔╝██║   ██║ " << '\n';
	wcout << L" \t \t ██║     ██║██║   ██║██╔══██║   ██║       ██╔══██║██╔══╝  ██╔══██╗██║   ██║ " << '\n';
	wcout << L" \t \t ███████╗██║╚██████╔╝██║  ██║   ██║       ██║  ██║███████╗██║  ██║╚██████╔╝ " << '\n';
	wcout << L" \t \t ╚══════╝╚═╝ ╚═════╝ ╚═╝  ╚═╝   ╚═╝       ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝  " << '\n';
	int wcoutMode = _setmode(_fileno(stdout), coutMode);

	int x = resolution.x / 2.5f;
	y = resolution.y / 3 * 2;
	IsGotoxy(x, y);
	cout << "게임 시작";
	IsGotoxy(x, y + 1);
	cout << "게임 정보";
	IsGotoxy(x, y + 2);
	cout << "게임 종료";

	IsGotoxy(x - 1, y + (int)eMenu);
	cout << ">";
}