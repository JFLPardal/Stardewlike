#include "pch.h"
#include "PlayerData.h"

#include "Constants.h"
#include "Enums.h"

std::map<StatAndOrientation, std::vector<sf::Vector2i>> PlayerData::m_stateToAnimation =
{
	{StatAndOrientation{idle, up} ,		{sf::Vector2i{1 * TILE_W, 3 * TILE_H} } },
	{StatAndOrientation{idle, right},	{sf::Vector2i(1 * TILE_W, 2 * TILE_H) } },
	{StatAndOrientation{idle, down},	{sf::Vector2i(1 * TILE_W, 0 * TILE_H) } },
	{StatAndOrientation{idle, left},	{sf::Vector2i(1 * TILE_W, 1 * TILE_H) } },
};

std::vector<sf::Vector2i> PlayerData::GetAnimationState(State aState, PossibleOrientation aOrientation) const
{
	StatAndOrientation statAndOrientation{ aState, aOrientation };
	return m_stateToAnimation.at(statAndOrientation);
}