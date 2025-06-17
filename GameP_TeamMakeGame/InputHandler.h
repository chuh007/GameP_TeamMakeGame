#pragma once
#include <vector>
#include "Enums.h"
class ICommand;
struct InputKey
{
	int vk;
	Key key;
};
class InputHandler
{
public:
	InputHandler();
public:
	ICommand* HandleInput();
	std::vector<InputKey> m_vecKeys;
};

