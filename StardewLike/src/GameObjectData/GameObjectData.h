#pragma once
#include "Enums.h"
#include "Animation.h"

/*
	GameObjectData is responsible for defining the interface with which
	any class is going to communicate with when trying to access that 
	GameObjects	Data
*/

class GameObjectData
{
public:
	typedef Vector2i SpriteSheedIndex;
	GameObjectData() = default;
	virtual ~GameObjectData() = default;

	virtual const Animation& GetAnimationState(State aState, PossibleOrientation aOrientation = up) const = 0;
};