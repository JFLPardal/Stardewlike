#pragma once
#include "Enums.h"

class GameObjectData
{
public:
	GameObjectData() = default;
	virtual ~GameObjectData() = default;

	virtual std::vector<sf::Vector2i> GetAnimationState(State aState, PossibleOrientation aOrientation = up) const = 0;
};