#pragma once

/*
	Item are the GameObjects that the Player can carry on his
	inventory.
*/

enum ItemType
{
	notDefined = -1,
	hoe = 1 , wateringCan
};

class Item
{
public:
	ItemType GetItemType() const { return m_type; }
protected:
	Item(ItemType aType) : m_type(aType) {};
private:
	ItemType m_type = ItemType::notDefined;
};