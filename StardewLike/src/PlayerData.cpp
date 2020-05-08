#include "pch.h"
#include "PlayerData.h"

#include "Enums.h"

std::map<State, std::vector<sf::Vector2i>> PlayerData::m_stateToAnimation =
{
	{idle, {sf::Vector2i{0,0} } },
	{walk, {sf::Vector2i{1,0} } },
};
