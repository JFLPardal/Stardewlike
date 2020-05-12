#pragma once
#include "TileInfo.h"
#include "IEvent.h"
/*
	GameObjectGridMap is responsible for holding all the tiles on the level
	that have some GameObject on them, as well as providing functionality 
	like adding and removing these GameObjects from the world.
*/

typedef IEvent<void(std::shared_ptr<GameObject>, const sf::Vector2i&)> TryToCreateGameObjectEvent;

#define TRY_CREATE_GAME_OBJECT(callbackFunction) std::function<void(std::shared_ptr<GameObject>, const sf::Vector2i&)>(std::bind(callbackFunction, this, std::placeholders::_1,std::placeholders::_2))

class GameObject;

class GameObjectGridMap
{
public:
	GameObjectGridMap();
	~GameObjectGridMap() = default;

	GameObject* CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck);
	//TileInfo* GetTile(const sf::Vector2i& aGridIndexToGet);

	void AddToGrid(std::shared_ptr<GameObject> aObjectToAdd, sf::Vector2i aGridIndex);

	std::unique_ptr<TryToCreateGameObjectEvent> OnTryToCreateGameObjectEvent;
private:
	std::set<TileInfo> m_tileInfo;
};