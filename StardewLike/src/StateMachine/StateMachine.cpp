#include "pch.h"
#include "StateMachine.h"

#include "GameObject.h"
#include "GameObjectData/GameObjectData.h"

StateMachine::StateMachine()
	:OnStateChangeEvent(std::make_unique<StateChangeEvent>())
{
}

void StateMachine::Start(GameObject* aOwner)
{
	m_owner = aOwner;
	m_data = m_owner->GetData();
}