#include "pch.h"
#include "GameObjectGridMap.h"

#include "TileInfo.h"

GameObject* GameObjectGridMap::CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck)
{
	auto tileToGet = m_tileInfo.find(TileInfo(nullptr, aGridIndexToCheck));

	if (tileToGet != m_tileInfo.end())
		return tileToGet->GetGameObject();
	return nullptr;
}

void GameObjectGridMap::AddToGrid(GameObject* aObjectToAdd, sf::Vector2i aGridIndex)
{
	//assert(aObjectToAdd != nullptr && "Can't add nullptr GameObject to the GameObjectGridMap");
	m_tileInfo.emplace(std::move(TileInfo(aObjectToAdd, aGridIndex)));
}