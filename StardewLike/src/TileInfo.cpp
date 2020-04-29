#include "pch.h"
#include "TileInfo.h"

#include "GameObject.h"
#include "Constants.h"

TileInfo::TileInfo(GameObject* aGameObject, const sf::Vector2i& aGridPosition)
	: m_GameObject(aGameObject)
	, m_gridPosition(aGridPosition)
{}

bool operator<(const TileInfo& aTile1, const TileInfo& aTile2)
{
	return aTile1.m_gridPosition.y * NUM_COLUMNS_IN_WINDOW + aTile1.m_gridPosition.x < aTile2.m_gridPosition.y * NUM_COLUMNS_IN_WINDOW + aTile2.m_gridPosition.x;
}
