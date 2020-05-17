#pragma once
#include "Enums.h"
#include "Components/Component.h"
/*
	Item are the GameObjects that the Player can carry on his
	inventory.
*/

class Item : public Component
{
public:
	ItemType GetItemType() const { return m_type; }
protected:
	Item(ItemType aType) : m_type(aType) {};
private:
	ItemType m_type = ItemType::notDefined;
};