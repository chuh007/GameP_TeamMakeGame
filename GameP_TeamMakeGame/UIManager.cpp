#include "UIManager.h"
#include "Console.h"
UIManager* UIManager::m_inst = nullptr;

UIManager::UIManager()
	: m_waveCntPos({ GetConsoleResolution().x / 4, 10 })
	, m_modeTxtPos({ GetConsoleResolution().x / 4 - 3, 13 })
	, m_Choice1Pos({ GetConsoleResolution().x / 50 - 3, 30 })
	, m_Choice2Pos({ GetConsoleResolution().x / 8 - 1, 30 })
	, m_Choice3Pos({ GetConsoleResolution().x / 4, 30 })
{
}

UIManager::~UIManager()
{
}

void UIManager::UpdateUI(const UIType& _type,
	const std::string& _str)
{
	switch (_type)
	{
	case UIType::WAVECNT:
		Gotoxy(m_waveCntPos.x, m_waveCntPos.y);
		break;
	case UIType::MODETXT:
		Gotoxy(m_modeTxtPos.x, m_modeTxtPos.y);
		break;
	case UIType::CHOICE1:
		Gotoxy(m_Choice1Pos.x, m_Choice1Pos.y);
		break;
	case UIType::CHOICE2:
		Gotoxy(m_Choice2Pos.x, m_Choice2Pos.y);
		break;
	case UIType::CHOICE3:
		Gotoxy(m_Choice3Pos.x, m_Choice3Pos.y);
		break;
	}
	cout << _str;
}

void UIManager::Init()
{
	Gotoxy(m_waveCntPos.x - 3, m_waveCntPos.y);
	cout << "웨이브";
	Gotoxy(m_modeTxtPos.x, m_modeTxtPos.y);
	cout << "!습격!  ";
}

