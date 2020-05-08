#include "pch.h"
#include "SeedData.h"

#include "Enums.h"
#include "Constants.h"

/// the vector is the grid position of each sprite on the tileSheet and the direction is the sprite of the player,
/// p.e. up has the coordenates, on the spritesheet, of the sprite of the player looking up
std::map<State, std::vector<sf::Vector2i>> SeedData::m_stateToAnimation =
{
	{buried,	{sf::Vector2i{0 * TILE_H,0} } },
	{plant,		{sf::Vector2i{1 * TILE_H,0} } },
	{fruit,		{sf::Vector2i{2 * TILE_H,0} } },
};

