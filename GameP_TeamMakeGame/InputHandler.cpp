#include <Windows.h>
#include "InputHandler.h"
#include "MoveCommand.h"
#include "FireCommand.h"

InputHandler::InputHandler()
{
	m_vecKeys.push_back({ 'W', Key::UP });
	m_vecKeys.push_back({ 'S', Key::DOWN });
	m_vecKeys.push_back({ 'A', Key::LEFT });
	m_vecKeys.push_back({ 'D', Key::RIGHT });
	m_vecKeys.push_back({ VK_SPACE, Key::SPACE });
	m_vecKeys.push_back({ VK_ESCAPE, Key::ESC });
}

Key InputHandler::TitleInput()
{
	for (auto& key : m_vecKeys)
	{
		bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isDown)
		{
			if(key.key != Key::LEFT && key.key != Key::RIGHT)
				return key.key;
		}
	}
	Sleep(30);
	return Key::NONE;
}

ICommand* InputHandler::HandleInput()
{
	for (auto& key : m_vecKeys)
	{
		bool isDown = (GetAsyncKeyState(key.vk) & 0x8000) != 0;
		if (isDown)
		{
			if (key.key < Key::SPACE)
				return new MoveCommand
				((Dir)key.key);
			else
				return new FireCommand
				(key.key);
		}

	}
	Sleep(30);
	return nullptr;
}
