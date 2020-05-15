#pragma once
#include "Component.h"

/*
	InteractWithWorld is responsible for calculating the tile the player 
	is trying to interact with and call the interaction of the GO that is 
	on that tile
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
	EventIndex m_mouseLeftClickedIndex = -2;
	Transform* m_transform{ nullptr };
	Orientation* m_orientation{ nullptr };
	Inventory* m_inventory{ nullptr };
};