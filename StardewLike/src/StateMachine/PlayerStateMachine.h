#pragma once
#include "StateMachine.h"
#include "Enums.h"

/*
	PlayerStateMachine represents the various states the player can be in
	as well as its transitions.
*/

class Orientation;

class PlayerStateMachine : public StateMachine
{
public:
	PlayerStateMachine();
	~PlayerStateMachine();

	void Start(GameObject* aOwner) override;
private:
	void OrientationChanged(PossibleOrientation aNewOrientation);

	static std::vector<State> m_possibleStates;
	Orientation* m_orientation;
	EventIndex m_OrientationChangedIndex = -2;
};