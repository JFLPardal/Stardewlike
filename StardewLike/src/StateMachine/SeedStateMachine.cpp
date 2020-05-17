#include "pch.h"
#include "SeedStateMachine.h"

std::vector<State> SeedStateMachine::m_possibleStates =
{
	State::buried, State::plant, State::fruit
};

SeedStateMachine::SeedStateMachine()
{
	m_currentState = State::buried;
}

void SeedStateMachine::Start(GameObject* aOwner)
{
	StateMachine::Start(aOwner);
	OnStateChangeEvent->TriggerEvent(State::fruit);
}
