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
    SetColor();
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
    cout << "=== ��Ʈ�� Ű �ȳ� ===\n"
        << "WASD : �ѱ� ��ġ �� ���� ����\n"
        << "�����̽��� : �Ѿ� �߻�\n"
        << "1,2,3 Ű : ���̺꺰 ���׷��̵� ����\n"
        << "ESC : ����â ����\n\n";


    cout << "=== �þ� ===\n"
        << "5/10/15 ���̺꿡�� �þ߰� �������ϴ�.\n"
        << "�� ���̴� ���� ���� ���� �νĵ˴ϴ�.\n\n";

    cout << "=== ���׷��̵� ���� ===\n"
        << "1) ���ݷ� ����    : �Ѿ� ������ ����\n"
        << "2) ���� ���� ���� : �߻� �ӵ� ����\n"
        << "3) ��ȣ�� ȹ��    : 1ȸ ��� ��ȣ�� (��ø �Ұ�)\n"
        << "�� ���׷��̵�� ���� �ð� �� ������ϴ�.\n\n";

    cout << "=== �� ���� ===\n"
        << "�� ����� �� (���� ����)\n";

    cout << "�� : �ٰ��� ���⿡ ";
    SetColor(COLOR::RED);
    cout << "��";
    SetColor();
    cout << "ǥ�� �� 1�� �� ������ ���� (5���̺����)\n";

    cout << "�� : �ݴ� �������� ���� (10���̺����)\n";

    cout << "�� : ���������� ����. ���� �� ȭ�鿡 ";
    SetColor(COLOR::YELLOW);
    cout << "��";
    SetColor();
    cout << "ǥ�� (15���̺����)\n\n";

    cout << "=== ���ӿ��� ȭ�� ===\n"
        << "��Ƴ��� ���̺� : ���� ���̺� �� ǥ��\n"
        << "���߷� : ���� ���� (%) ǥ�� (�߻� ������ 0%)\n";
}
