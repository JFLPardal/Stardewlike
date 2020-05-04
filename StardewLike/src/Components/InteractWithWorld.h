#pragma once
#include "Component.h"
#include "IEvent.h"

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

typedef IEvent<void(std::unique_ptr<GameObject>, const sf::Vector2i&)> TryToCreateGameObjectEvent;

#define TRY_CREATE_GAME_OBJECT(callbackFunction) std::function<void(std::unique_ptr<GameObject>, const sf::Vector2i&)>(std::bind(callbackFunction, this, std::placeholders::_1,std::placeholders::_2))

class InteractWithWorld : public Component
{
public:
	InteractWithWorld(WindowEventHandler* aWindowEventHandler, GameObjectGridMap& aTileData);
	~InteractWithWorld();

	void Start() override;
	std::unique_ptr<TryToCreateGameObjectEvent> OnTryToCreateGameObjectEvent;
private:
	void Interact(int aScreenCoordsX, int aScreenCoordsY);

	WindowEventHandler* m_windowEventHandler{ nullptr };
	GameObjectGridMap* m_GOgridMap{ nullptr };
	EventIndex m_mouseLeftClickedIndex = -1;
	Transform* m_transform{ nullptr };
	Orientation* m_orientation{ nullptr };
	Inventory* m_inventory{ nullptr };
};