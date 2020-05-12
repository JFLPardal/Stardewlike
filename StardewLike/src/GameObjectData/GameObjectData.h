#pragma once
#include "Enums.h"
#include "Animation.h"

class GameObjectData
{
public:
	typedef Vector2i SpriteSheedIndex;
	GameObjectData() = default;
	virtual ~GameObjectData() = default;

	virtual const Animation& GetAnimationState(State aState, PossibleOrientation aOrientation = up) const = 0;
};