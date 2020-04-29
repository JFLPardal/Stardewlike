#pragma once
#include "TileInfo.h"

/*
	TileData is responsible for holding all the tiles on the level
	that have some GameObject on them, as well as providing functionality 
	like adding and removing these GameObjects from the world.
*/

class GameObject;

class TileData
{
public:
	TileData() = default;
	~TileData() = default;

	GameObject* CheckForGameObjectOnTile(const sf::Vector2i& aGridIndexToCheck);

	void AddToGrid(GameObject* aObjectToAdd, sf::Vector2i aGridIndex);
private:
	std::set<TileInfo> m_tileInfo;
};