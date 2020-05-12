#pragma once
#include "StateMachine.h"

class GameObject;

class SeedStateMachine : public StateMachine
{
public:
	SeedStateMachine();

	void Start(GameObject* aOwner) override;
private:
	static std::vector<State> m_possibleStates;
};
