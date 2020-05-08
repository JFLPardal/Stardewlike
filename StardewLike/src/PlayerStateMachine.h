#pragma once
#include "StateMachine.h"
#include "Enums.h"

class Orientation;

class PlayerStateMachine : public StateMachine
{
public:
	PlayerStateMachine() = default;

	void Start(GameObject* aOwner) override;
private:
	//void OrientationChanged(PossibleOrientation aNewOrientation);

	Orientation* m_orientation{ nullptr };
};