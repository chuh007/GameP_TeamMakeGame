#include "GameOverScene.h"
#include "GameManager.h"
#include "Console.h"
#include "Define.h"
#include "Enums.h"

GameOverScene::GameOverScene()
{
	m_inputHandler = new InputHandler();
	resolution = { 0,0 };
	resolution = GetConsoleResolution();
	nowScene = SCENE::GameOver;
}

GameOverScene::~GameOverScene()
{
	SAFE_DELETE(m_inputHandler);
}

void GameOverScene::Init()
{
	system("cls");
	nowScene = SCENE::GameOver;
	Render();
}

void GameOverScene::Update()
{
	Key key = m_inputHandler->GameOverInput();
	if (key == Key::SPACE)
	{
		isFirstLoadScene = true;
		nowScene = SCENE::Title;
		system("cls");
	}
}

void GameOverScene::Render()
{
	int coutMode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"\t\t\t ██████╗  █████╗ ███╗   ███╗███████╗ ██████╗ ██╗   ██╗███████╗██████╗ " << '\n';
	wcout << L"\t\t\t██╔════╝ ██╔══██╗████╗ ████║██╔════╝██╔═══██╗██║   ██║██╔════╝██╔══██╗" << '\n';
	wcout << L"\t\t\t██║  ███╗███████║██╔████╔██║█████╗  ██║   ██║██║   ██║█████╗  ██████╔╝" << '\n';
	wcout << L"\t\t\t██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ██║   ██║╚██╗ ██╔╝██╔══╝  ██╔══██╗" << '\n';
	wcout << L"\t\t\t╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗╚██████╔╝ ╚████╔╝ ███████╗██║  ██║" << '\n';
	wcout << L"\t\t\t ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝ ╚═════╝   ╚═══╝  ╚══════╝╚═╝  ╚═╝" << '\n';

	int wcoutMode = _setmode(_fileno(stdout), coutMode);


	cout << "\t\t\t\t\t=======================================" << '\n';
	cout << "\t\t\t\t\t=                                     =" << '\n';
	cout << GetWaveString() << '\n';
	cout << GetAccuracyString() << '\n';
	cout << "\t\t\t\t\t=                                     =" << '\n';
	cout << "\t\t\t\t\t=======================================" << '\n';
}

std::string GameOverScene::GetWaveString()
{
	int waveCount = GameManager::GetInst()->GetWaveCount();
	std::string waveStr = "살아남은 웨이브 : " + std::to_string(waveCount);
	int totalSpace = 37;
	int spaceSize = (totalSpace - waveStr.length()) / 2;

	std::string wave = "\t\t\t\t\t=";
	for (int i = 0; i < spaceSize; i++)
	{
		wave += ' ';
	}
	wave += waveStr;
	for (int i = 0; i < spaceSize; i++)
	{
		wave += ' ';
	}
	wave += '=';
	return wave;
}

std::string GameOverScene::GetAccuracyString()
{
	float accuracyCount = 0;// 명중률 넣기
	std::string accuracyStr = "명중률 : " + std::to_string(accuracyCount);
	int totalSpace = 37;
	int spaceSize = (totalSpace - accuracyStr.length()) / 2;

	std::string accuracy = "\t\t\t\t\t=";
	for (int i = 0; i < spaceSize; i++)
	{
		accuracy += ' ';
	}
	accuracy += accuracyStr;
	for (int i = 0; i < spaceSize; i++)
	{
		accuracy += ' ';
	}
	accuracy += '=';
	return accuracy;
}
