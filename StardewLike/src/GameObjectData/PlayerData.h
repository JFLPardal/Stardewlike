#pragma once
#include "GameObjectData.h"

typedef std::pair<State, PossibleOrientation> StatAndOrientation;

/*
	PlayerData holds the Data of the Player, like the various animations the
	player has.
*/

class PlayerData : public GameObjectData
{
public:
	PlayerData() = default;
	const Animation& GetAnimationState(State aState, PossibleOrientation aOrientation) const override;
private:
	static std::map<StatAndOrientation, Animation> m_stateToAnimation;
};