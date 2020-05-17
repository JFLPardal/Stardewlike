#include "pch.h"
#include "GridRepresentation.h"

#include "Constants.h"

Vector2i GridRepresentation::ScreenToGridPosition(sf::Vector2f aScreenPos)
{
	return ScreenToGridPosition(aScreenPos.x, aScreenPos.y);
}

sf::Vector2f GridRepresentation::GridToScreenPosition(Vector2i aGridPos)
{
	return sf::Vector2f(static_cast<float>(aGridPos.X() * TILE_W) + TILE_W * .5f,
						static_cast<float>(aGridPos.Y() * TILE_H) + TILE_H * .5f);
}

Vector2i GridRepresentation::ScreenToGridPosition(float aScreenPosX, float aScreenPosY)
{	
	auto gridX = aScreenPosX / static_cast<float>(TILE_W);
	if (gridX == std::floor(gridX))	// if the value is right on the edge of a tile, it still belongs to the tile, not to the next one
		gridX--;

	auto gridY = aScreenPosY / static_cast<float>(TILE_H);
	if (gridY == std::floor(gridX))	
		gridY--;

	Vector2i gridPosition(static_cast<int>(std::floor(gridX)),
						  static_cast<int>(std::floor(gridY)));
	assert(gridPosition.X() >= 0 && gridPosition.Y() >= 0
			&& gridPosition.X() < NUM_COLUMNS_IN_WINDOW 
			&& gridPosition.Y() < NUM_ROWS_IN_WINDOW 
			&& "invalid grid position");

	return gridPosition;
}

