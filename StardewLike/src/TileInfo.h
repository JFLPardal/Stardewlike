#pragma once

/*
	TileInfo is responsible for storing the data that each tile holds,
	its grid position and a reference to the object that is on that position.
*/

class GameObject;

class TileInfo
{
public:
	TileInfo(GameObject* aGameObject, const sf::Vector2i& aGridIndex);
	~TileInfo();

	GameObject* GetGameObject() const { return m_GameObject.get(); }

	friend bool operator<(const TileInfo& aTile1, const TileInfo& aTile2);
private:
	std::shared_ptr<GameObject> m_GameObject;
	sf::Vector2i m_gridPosition;
};