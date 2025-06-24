#include<io.h>
#include<Windows.h>
#include "TitleManager.h"
#include "Console.h"

TitleManager* TitleManager::m_inst = __nullptr;

TitleManager::TitleManager()
	:eMenu(Menu::FAIL)
{
	resolution = { 0,0 };
	eMenu = Menu::START;
	resolution = GetConsoleResolution();
}

void TitleManager::Update(Key key, Scene& curScene)
{
	if (curScene == Scene::Title)
	{
		int x = resolution.x / 2.5f;
		int y = resolution.y / 3 * 2;
		
		int nowMenu = (int)eMenu;


		switch (key)
		{
		case Key::UP:
			nowMenu--;
			if (0 <= nowMenu && nowMenu <= 2)
			{
				IsGotoxy(x - 1, y + (int)eMenu);
				cout << " ";
				eMenu = (Menu)nowMenu;
				Sleep(75);
			}
			break;
		case Key::DOWN:
			nowMenu++;
			if (0 <= nowMenu && nowMenu <= 2)
			{
				IsGotoxy(x - 1, y + (int)eMenu);
				cout << " ";
				eMenu = (Menu)nowMenu;
				Sleep(75);
			}
			break;
		case Key::SPACE:
			if (eMenu == Menu::START)
			{
				system("cls");
				curScene = Scene::Game;
				return;
			}
			if (eMenu == Menu::INFO)
			{
				system("cls");
				curScene = Scene::INFO;
				return;
			}
			if (eMenu == Menu::QUIT)
			{
				system("cls");
				curScene = Scene::QUIT;
				return;
			}
			break;
		}
		RenderTitle();
	}
	if (curScene == Scene::INFO)
	{
		system("cls");
		if (key == Key::ESC)
		{
			curScene = Scene::Title;
			return;
		}
		RenderInfo();
	}

}

void TitleManager::RenderInfo()
{
	cout << "WASD를 통하여서 보는 방향 변경 \n 스페이스바로 총알 발사";
}


void TitleManager::RenderTitle()
{
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
