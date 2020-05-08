#include "pch.h"
#include "SeedStateMachine.h"

std::vector<State> SeedStateMachine::m_possibleStates =
{
	buried, plant, fruit
};

SeedStateMachine::SeedStateMachine()
{
	m_currentState = buried;
}

void SeedStateMachine::Start(GameObject* aOwner)
{
	StateMachine::Start(aOwner);
	OnStateChangeEvent->TriggerEvent(plant);
}
