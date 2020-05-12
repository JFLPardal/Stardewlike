#pragma once
#include "GameObjectData.h"

class SeedData : public GameObjectData
{
public:
	SeedData() = default;

	// parameter PossibleOrientation is not used on the seed's case but needs to be here to adhere at the GOData's interface
	const Animation& GetAnimationState(State aState, PossibleOrientation aOrientation) const override { return m_stateToAnimation.at(aState); }
private:
	static std::map<State, Animation> m_stateToAnimation;
};