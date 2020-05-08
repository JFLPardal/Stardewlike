#pragma once
#include "GameObjectData.h"

class SeedData : public GameObjectData
{
public:
	SeedData() = default;
	std::vector <sf::Vector2i> GetAnimationState(State aState) const override { return m_stateToAnimation.at(aState); }
private:
	static std::map<State, std::vector<sf::Vector2i>> m_stateToAnimation;
};