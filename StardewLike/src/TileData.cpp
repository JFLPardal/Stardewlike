#include "pch.h"
#include "TileData.h"

#include "TileInfo.h"

GameObject* TileData::CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck)
{
	auto tileToGet = m_tileInfo.find(TileInfo(nullptr, aGridIndexToCheck));

	if (tileToGet != m_tileInfo.end())
		return tileToGet->GetGameObject();
	return nullptr;
}

void TileData::AddToGrid(GameObject* aObjectToAdd, sf::Vector2i aGridIndex)
{
	//assert(aObjectToAdd != nullptr && "Can't add nullptr GameObject to the TileData");
	m_tileInfo.emplace(TileInfo(aObjectToAdd, aGridIndex));
}