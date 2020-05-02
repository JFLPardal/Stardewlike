#pragma once
#include "TileInfo.h"

/*
	GameObjectGridMap is responsible for holding all the tiles on the level
	that have some GameObject on them, as well as providing functionality 
	like adding and removing these GameObjects from the world.
*/

class GameObject;

class GameObjectGridMap
{
public:
	GameObjectGridMap() = default;
	~GameObjectGridMap() = default;

	GameObject* CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck);

	void AddToGrid(std::shared_ptr<GameObject> aObjectToAdd, sf::Vector2i aGridIndex);
private:
	std::set<TileInfo> m_tileInfo;
};