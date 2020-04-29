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
	~TileInfo() = default;

	GameObject* GetGameObject() const { return m_GameObject; }

	// TODO extract these magic numbers FOR THE LOVE OF GOOOOOOD, 32 is the number of tiles per row
	friend bool operator<(const TileInfo& ti1, const TileInfo& ti2);
private:
	GameObject* m_GameObject;
	sf::Vector2i m_gridPosition;
};