#pragma once
#include "Component.h"

/*
	InteractWithWorld is responsible for the attempt of the player to interact with the world
	and will be responsible	for passing down that interaction attempt to the correct tile.
*/

class GameObject;
class WindowEventHandler;
class GameObjectGridMap;
class Transform;
class Orientation;
class Inventory;

class InteractWithWorld : public Component
{
public:
	InteractWithWorld(WindowEventHandler* aWindowEventHandler, GameObjectGridMap& aTileData);
	~InteractWithWorld();

	void Start() override;
private:
	void Interact(int aScreenCoordsX, int aScreenCoordsY);

	WindowEventHandler* m_windowEventHandler{ nullptr };
	GameObjectGridMap* m_GOgridMap{ nullptr };
	EventIndex m_mouseLeftClickedIndex = -1;
	Transform* m_transform{ nullptr };
	Orientation* m_orientation{ nullptr };
	Inventory* m_inventory{ nullptr };
};