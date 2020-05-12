#pragma once
#include "Component.h"

/*
	Inventory is responsible for holding all the items
	the player is currently carrying and a reference to the item 
	the player currently has equipped.
*/

class GameObject;
class WindowEventHandler;

class Inventory : public Component
{
public:
	Inventory(WindowEventHandler* aWindow);
	~Inventory();

	// don't allow changes to the object pointed to
	GameObject* const ObjectBeingHeld() const { return m_objectsHeld.at(m_indexOfCurrentGO).get(); }
private:
	void ChangeActiveItem(int aNewIndex);

	WindowEventHandler* m_windowEventHandler{ nullptr };
	EventIndex m_numberKeyPressedIndex = -3;

	std::vector<std::unique_ptr<GameObject>> m_objectsHeld;
	size_t m_indexOfCurrentGO = 0;
};