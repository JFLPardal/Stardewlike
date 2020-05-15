#pragma once
#include "StateMachine.h"

/*
	SeedStateMachine represents the various states the Seed can be in
	as well as its transitions.
*/

class GameObject;

class SeedStateMachine : public StateMachine
{
public:
	SeedStateMachine();

	void Start(GameObject* aOwner) override;
private:
	static std::vector<State> m_possibleStates;
};
