#include "Core.h"
#include "ObjectManager.h"

void Core::Run()
{
	while (true)
	{
		Update();
		// �����ӽ�ũ
	}
}

void Core::Update()
{
	ObjectManager::GetInst()->Update();
}

