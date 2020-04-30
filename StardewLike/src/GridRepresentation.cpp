#include "pch.h"
#include "GridRepresentation.h"

#include "Constants.h"

sf::Vector2i GridRepresentation::ScreenToGridPosition(sf::Vector2f aScreenPos)
{
	return ScreenToGridPosition(aScreenPos.x, aScreenPos.y);
}

sf::Vector2f GridRepresentation::GridToScreenPosition(sf::Vector2i aGridPos)
{
	return sf::Vector2f(aGridPos.x * TILE_W, aGridPos.y * TILE_H);
}

sf::Vector2i GridRepresentation::ScreenToGridPosition(float aScreenPosX, float aScreenPosY)
{	
	auto gridX = aScreenPosX / (float) TILE_W;
	if (gridX == std::floor(gridX))	// if the value is right on the edge of a tile, it still belongs to the tile, not to the next one
		gridX--;

	auto gridY = aScreenPosY / (float) TILE_H;
	if (gridY == std::floor(gridX))	
		gridY--;

	sf::Vector2i gridPosition(std::floor(gridX), std::floor(gridY));
	assert(gridPosition.x >= 0 && gridPosition.y >= 0 
			&& gridPosition.x < NUM_COLUMNS_IN_WINDOW 
			&& gridPosition.y < NUM_ROWS_IN_WINDOW 
			&& "invalid grid position");

	return gridPosition;
}

