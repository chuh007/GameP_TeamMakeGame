#pragma once
#include "Enums.h"
class IFireable
{
public:
	virtual ~IFireable() = default;
	virtual void Fire() abstract;
};

