#pragma once
#include "GameObjectData.h"

class SeedData : public GameObjectData
{
public:
	SeedData() = default;

	// parameter PossibleOrientation is not used on the seed's case but needs to be here to adhere at the GOData's interface
	std::vector <sf::Vector2i> GetAnimationState(State aState, PossibleOrientation aOrientation) const override { return m_stateToAnimation.at(aState); }
private:
	static std::map<State, std::vector<sf::Vector2i>> m_stateToAnimation;
};