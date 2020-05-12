#include "pch.h"
#include "SeedData.h"

#include "Enums.h"
#include "Constants.h"

/// the vector is the grid position of each sprite on the tileSheet and the direction is the sprite of the player,
/// p.e. up has the coordenates, on the spritesheet, of the sprite of the player looking up
std::map<State, Animation> SeedData::m_stateToAnimation =
{
	{buried,	Animation{Vector2i(0 * TILE_H,0) } } ,
	{plant,		Animation{Vector2i(1 * TILE_H,0) } },
	{fruit,		Animation{Vector2i(2 * TILE_H,0) } },
};

