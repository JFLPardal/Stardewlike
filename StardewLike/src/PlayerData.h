#pragma once
#include "GameObjectData.h"

typedef std::pair<State, PossibleOrientation> StatAndOrientation;

class PlayerData : public GameObjectData
{
public:
	PlayerData() = default;
	std::vector<sf::Vector2i> GetAnimationState(State aState, PossibleOrientation aOrientation) const override;
private:
	static std::map<StatAndOrientation, std::vector<sf::Vector2i>> m_stateToAnimation;
};