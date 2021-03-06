#include "pch.h"
#include "GameObjectGridMap.h"

#include "TileInfo.h"
#include "GameObject.h"

GameObjectGridMap::GameObjectGridMap()
	: OnTryToCreateGameObjectEvent(std::make_unique<TryToCreateGameObjectEvent>())
	, OnRemoveGameObjectEvent(std::make_unique<RemoveGameObjectEvent>())
{
}

GameObject* GameObjectGridMap::CheckForGameObjectOnTile(const Vector2i& aGridIndexToCheck)
{
	auto tileToGet = m_tileInfo.find(TileInfo(nullptr, aGridIndexToCheck.GetVector()));

	if (tileToGet != m_tileInfo.end())
		return tileToGet->GetGameObject();
	return nullptr;
}

void GameObjectGridMap::AddToGrid(std::shared_ptr<GameObject> aObjectToAdd, Vector2i aGridIndex)
{
	//assert(aObjectToAdd != nullptr && "Can't add nullptr GameObject to the GameObjectGridMap");
	OnTryToCreateGameObjectEvent->TriggerEvent(aObjectToAdd, aGridIndex);
	m_tileInfo.emplace(std::move(TileInfo(aObjectToAdd, aGridIndex.GetVector())));
}

void GameObjectGridMap::RemoveFromGrid(Vector2i aGridIndex)
{
	const TileInfo* tileToRemove{nullptr};
	for(auto& tileInfo : m_tileInfo)
	{
		if (tileInfo.GetPosition() == aGridIndex.GetVector())
		{
			tileToRemove = &tileInfo;
			break;
		}
	}
	if (tileToRemove != nullptr)
	{
		OnRemoveGameObjectEvent->TriggerEvent(tileToRemove->GetGameObjectOwnership());
		m_tileInfo.erase(*tileToRemove);
	}
}
