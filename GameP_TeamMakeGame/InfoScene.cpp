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
    cout << "=== 컨트롤 키 안내 ===\n"
        << "WASD : 총구 위치 및 시점 변경\n"
        << "스페이스바 : 총알 발사\n"
        << "1,2,3 키 : 웨이브별 업그레이드 선택\n"
        << "ESC : 설명창 종료\n\n";


    cout << "=== 시야 ===\n"
        << "5/10/15 웨이브에서 시야가 좁아집니다.\n"
        << "※ 보이는 영역 내의 적만 인식됩니다.\n\n";

    cout << "=== 업그레이드 종류 ===\n"
        << "1) 공격력 증가    : 총알 데미지 증가\n"
        << "2) 공격 간격 감소 : 발사 속도 증가\n"
        << "3) 보호막 획득    : 1회 방어 보호막 (중첩 불가)\n"
        << "※ 업그레이드는 일정 시간 후 사라집니다.\n\n";

    cout << "=== 적 종류 ===\n"
        << "※ 평범한 적 (지속 출현)\n";

    cout << "★ : 다가올 방향에 ";
    SetColor(COLOR::RED);
    cout << "♨";
    SetColor();
    cout << "표시 후 1초 뒤 빠르게 접근 (5웨이브부터)\n";

    cout << "＆ : 반대 방향으로 공격 (10웨이브부터)\n";

    cout << "◎ : 투명하지만 느림. 존재 시 화면에 ";
    SetColor(COLOR::YELLOW);
    cout << "♨";
    SetColor();
    cout << "표시 (15웨이브부터)\n\n";

    cout << "=== 게임오버 화면 ===\n"
        << "살아남은 웨이브 : 최종 웨이브 수 표시\n"
        << "명중률 : 적중 비율 (%) 표시 (발사 없으면 0%)\n";
}
