#include "pch.h"
#include "TileInfo.h"

#include "GameObject.h"
#include "Constants.h"

TileInfo::TileInfo(std::shared_ptr<GameObject> aGameObject, const sf::Vector2i& aGridPosition) noexcept
	: m_GameObject(aGameObject)
	, m_gridPosition(aGridPosition)
{}


bool operator<(const TileInfo& aTile1, const TileInfo& aTile2) noexcept
{
	return aTile1.m_gridPosition.y * NUM_COLUMNS_IN_WINDOW + aTile1.m_gridPosition.x < aTile2.m_gridPosition.y * NUM_COLUMNS_IN_WINDOW + aTile2.m_gridPosition.x;
}

TileInfo::~TileInfo()
{
	printf("tileInfo destroyed\n");
}
