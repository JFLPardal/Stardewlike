#include "pch.h"
#include "TileInfo.h"

#include "GameObject.h"

TileInfo::TileInfo(GameObject* aGameObject, const sf::Vector2i& aGridPosition)
	: m_GameObject(aGameObject)
	, m_gridPosition(aGridPosition)
{}

bool operator<(const TileInfo& aTile1, const TileInfo& aTile2)
{
	return aTile1.m_gridPosition.y * 32 + aTile1.m_gridPosition.x < aTile2.m_gridPosition.y * 32 + aTile2.m_gridPosition.x;
}
