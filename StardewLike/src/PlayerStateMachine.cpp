#include "pch.h"
#include "PlayerStateMachine.h"

#include "Components/Orientation.h"
#include "GameObject.h"

void PlayerStateMachine::Start(GameObject* aOwner)
{
	StateMachine::Start(aOwner);
	m_orientation = m_owner->GetComponent<Orientation>();
}
