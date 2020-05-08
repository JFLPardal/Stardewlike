#pragma once
#include "GameObjectData.h"

class PlayerData : public GameObjectData
{
public:
	PlayerData() = default;
	std::vector<sf::Vector2i> GetAnimationState(State aState) const override { return m_stateToAnimation.at(aState); }
private:
	static std::map<State, std::vector<sf::Vector2i>> m_stateToAnimation;
};