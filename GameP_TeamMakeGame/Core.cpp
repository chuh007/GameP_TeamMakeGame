#include "Core.h"
#include "ObjectManager.h"

void Core::Run()
{
	while (true)
	{
		Update();
		// ÇÁ·¹ÀÓ½ÌÅ©
	}
}

void Core::Update()
{
	ObjectManager::GetInst()->Update();
}

