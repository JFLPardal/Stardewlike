#include "pch.h"
#include "PlayerData.h"

#include "Constants.h"
#include "Enums.h"

std::map<StatAndOrientation, Animation> PlayerData::m_stateToAnimation =
{	
	{StatAndOrientation{State::idle, PossibleOrientation::up} ,		Animation{Vector2i(1 * TILE_W, 3 * TILE_H) } },
	{StatAndOrientation{State::idle, PossibleOrientation::right},	Animation{Vector2i(1 * TILE_W, 2 * TILE_H) } },
	{StatAndOrientation{State::idle, PossibleOrientation::down},	Animation{Vector2i(1 * TILE_W, 0 * TILE_H) } },
	{StatAndOrientation{State::idle, PossibleOrientation::left},	Animation{Vector2i(1 * TILE_W, 1 * TILE_H) } },
};

const Animation& PlayerData::GetAnimationState(State aState, PossibleOrientation aOrientation) const
{
	StatAndOrientation statAndOrientation{ aState, aOrientation };
	return m_stateToAnimation.at(statAndOrientation);
}