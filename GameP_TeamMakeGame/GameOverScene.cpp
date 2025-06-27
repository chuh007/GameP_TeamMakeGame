#include "GameOverScene.h"
#include "GameManager.h"
#include "ObjectManager.h"
#include "EnemyCollisionManager.h"
#include "Console.h"
#include "Define.h"
#include "Enums.h"
#include <string>
#include <sstream>
#include <iomanip>

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
	EnemyCollisionManager::GetInst()->SetHit(0);
	GameManager::GetInst()->SetMuzzleFireCount(0);
}

void GameOverScene::Update()
{
	Key key = m_inputHandler->InfoInput();
	if (key == Key::ESC)
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


	cout << "\t\t\t\t\t========================================" << '\n';
	cout << "\t\t\t\t\t=                                      =" << '\n';
	cout << GetWaveString() << '\n';
	cout << GetAccuracyString() << '\n';
	cout << "\t\t\t\t\t=                                      =" << '\n';
	cout << "\t\t\t\t\t========================================" << '\n';
	cout << "\n\n\n \t\t\t\t\t ESC를 눌러 타이틀로 돌아가기";
}

std::string GameOverScene::GetWaveString()
{
	int waveCount = GameManager::GetInst()->GetWaveCount();
	std::string waveStr = "살아남은 웨이브 : " + std::to_string(waveCount);
	const int totalSpace = 38;

	int blankTotal = totalSpace - waveStr.length();
	int leftPadding = blankTotal / 2;
	int rightPadding = blankTotal - leftPadding;

	std::string wave = "\t\t\t\t\t=";
	wave.append(leftPadding, ' ');
	wave += waveStr;
	wave.append(rightPadding, ' ');
	wave += '=';

	return wave;
}

std::string GameOverScene::GetAccuracyString()
{
	int hit = EnemyCollisionManager::GetInst()->GetHit();
	int fire = GameManager::GetInst()->GetMuzzleFireCount();

	float accuracyCount = 0.0f;
	if (hit > 0 && fire > 0)
	{
		accuracyCount = (float(hit) / fire) * 100.0f;
	}

	std::stringstream ss;
	ss << std::fixed << std::setprecision(2) << accuracyCount;
	std::string accuracyStr = "명중률 : " + ss.str() + "%";

	const int totalSpace = 38;
	int blankTotal = totalSpace - accuracyStr.length();
	int leftPadding = blankTotal / 2;
	int rightPadding = blankTotal - leftPadding;

	std::string accuracy = "\t\t\t\t\t=";
	accuracy.append(leftPadding, ' ');
	accuracy += accuracyStr;
	accuracy.append(rightPadding, ' ');
	accuracy += '=';

	return accuracy;
}
