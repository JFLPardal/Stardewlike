#include "pch.h"
#include "GameObjectGridMap.h"

#include "TileInfo.h"
#include "GameObject.h"

GameObjectGridMap::GameObjectGridMap()
	: OnTryToCreateGameObjectEvent(std::make_unique<TryToCreateGameObjectEvent>())
{
}

GameObject* GameObjectGridMap::CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck)
{
	auto tileToGet = m_tileInfo.find(TileInfo(nullptr, aGridIndexToCheck));

	if (tileToGet != m_tileInfo.end())
		return tileToGet->GetGameObject();
	return nullptr;
}
/*
TileInfo* GameObjectGridMap::GetTile(const sf::Vector2i& aGridIndexToGet)
{
	auto tileToGet = m_tileInfo.find(TileInfo(nullptr, aGridIndexToGet));
	TileInfo tilePointer = *tileToGet;
	if (tileToGet != m_tileInfo.end())
		return &tilePointer;
}*/

void GameObjectGridMap::AddToGrid(std::shared_ptr<GameObject> aObjectToAdd, sf::Vector2i aGridIndex)
{
	//assert(aObjectToAdd != nullptr && "Can't add nullptr GameObject to the GameObjectGridMap");
	OnTryToCreateGameObjectEvent->TriggerEvent(aObjectToAdd, aGridIndex);
	m_tileInfo.emplace(std::move(TileInfo(aObjectToAdd, aGridIndex)));
}