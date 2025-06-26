#include "InfoScene.h"
#include "Define.h"
#include "Console.h"

InfoScene::InfoScene()
{
	m_inputHandler = new InputHandler();
	nowScene = SCENE::INFO;
}

InfoScene::~InfoScene()
{
	SAFE_DELETE(m_inputHandler);
}

void InfoScene::Init()
{
	system("cls");
	nowScene = SCENE::INFO;
	RenderInfo();
}

void InfoScene::Update()
{
	Key key = m_inputHandler->InfoInput();
	if (key == Key::ESC)
	{
		nowScene = SCENE::Title;
		isFirstLoadScene = true;
		system("cls");
	}
}

void InfoScene::RenderInfo()
{
	cout << "WASD�� ���Ͽ��� ���� ���� ���� \n �����̽��ٷ� �Ѿ� �߻�";
}
