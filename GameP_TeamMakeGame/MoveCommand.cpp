#include "MoveCommand.h"
#include "IMovable.h"
#include "GameObject.h"

MoveCommand::MoveCommand(Dir _dir)
	: m_dir(_dir)
{
}

void MoveCommand::Execute(GameObject* _actor)
{
	IMovable* mover = dynamic_cast<IMovable*>(_actor);
	if (mover)
	{
		mover->Move(m_dir);
	}
}
