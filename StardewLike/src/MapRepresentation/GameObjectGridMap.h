#pragma once
#include "TileInfo.h"
#include "IEvent.h"
/*
	GameObjectGridMap is responsible for holding all the tiles on the level
	that have some GameObject on them, as well as providing functionality 
	like adding and removing these GameObjects from the world.
*/

typedef IEvent<void(std::shared_ptr<GameObject>, const sf::Vector2i&)> TryToCreateGameObjectEvent;
typedef IEvent<void(std::shared_ptr<GameObject>)> RemoveGameObjectEvent;

#define TRY_CREATE_GAME_OBJECT(callbackFunction) std::function<void(std::shared_ptr<GameObject>, const sf::Vector2i&)>(std::bind(callbackFunction, this, std::placeholders::_1,std::placeholders::_2))
#define REMOVE_GAME_OBJECT(callbackFunction) std::function<void(std::shared_ptr<GameObject>)>(std::bind(callbackFunction, this, std::placeholders::_1))

class GameObject;

class GameObjectGridMap
{
public:
	GameObjectGridMap();
	~GameObjectGridMap() = default;

	GameObject* CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck);

	void AddToGrid(std::shared_ptr<GameObject> aObjectToAdd, sf::Vector2i aGridIndex);
	void RemoveFromGrid(sf::Vector2i aGridIndex);

	std::unique_ptr<TryToCreateGameObjectEvent> OnTryToCreateGameObjectEvent;
	std::unique_ptr<RemoveGameObjectEvent> OnRemoveGameObjectEvent;
private:
	std::set<TileInfo> m_tileInfo;
};