#include "pch.h"
#include "PlayerStateMachine.h"

#include "Components/Orientation.h"
#include "GameObject.h"

std::vector<State> PlayerStateMachine::m_possibleStates =
{
	walk, idle
};

PlayerStateMachine::PlayerStateMachine()
{
	m_currentState = idle;
}

void PlayerStateMachine::Start(GameObject* aOwner)
{
	StateMachine::Start(aOwner);
	m_OrientationChangedIndex = m_owner->GetComponent<Orientation>()->OnOrientationChangedEvent->AddCallback(ORIENTATION_CHANGED(&PlayerStateMachine::OrientationChanged));
	OnStateChangeEvent->TriggerEvent(idle);
}

void PlayerStateMachine::OrientationChanged(PossibleOrientation aNewOrientation)
{
	OnStateChangeEvent->TriggerEvent(m_currentState);
}

PlayerStateMachine::~PlayerStateMachine()
{
	if (m_owner->GetComponent<Orientation>() != nullptr)
		m_orientation->OnOrientationChangedEvent->RemoveCallback(m_OrientationChangedIndex);
}
