#pragma once
#include "Component.h"

/*
	Inventory is responsible for having a reference to all the items
	the player is currently carrying and a reference to the item 
	the player currently has equipped.
*/

class GameObject;

class Inventory : public Component
{
public:
	Inventory();
	// don't allow changes to the object pointed to
	GameObject* const ObjectBeingHeld() const { return m_objectBeingHeld.get(); }
private:
	std::unique_ptr<GameObject> m_objectBeingHeld;
};