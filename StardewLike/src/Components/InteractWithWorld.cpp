#include "pch.h"
#include "InteractWithWorld.h"

#include "WindowEventHandler.h"
#include "Transform.h"
#include "Orientation.h"
#include "GameObject.h"
#include "GameObjectGridMap.h"
#include "Inventory.h"
#include "IInteractable.h"
#include "Seed.h"

InteractWithWorld::InteractWithWorld(WindowEventHandler* aWindowEventHandler, GameObjectGridMap& aGameObjectgridMap)
	: OnTryToCreateGameObjectEvent(std::make_unique<TryToCreateGameObjectEvent>())
	, m_windowEventHandler(aWindowEventHandler)
	, m_GOgridMap(&aGameObjectgridMap)
{
}

void InteractWithWorld::Start()
{
	m_mouseLeftClickedIndex = m_windowEventHandler->m_onMouseLeftClickedEvent->AddCallback(MOUSE_LEFT_CLICKED(&InteractWithWorld::Interact));
	m_transform = m_owner->GetComponent<Transform>();
	m_orientation = m_owner->GetComponent<Orientation>();
	m_inventory = m_owner->GetComponent<Inventory>();
}

void InteractWithWorld::Interact(int aScreenCoordsX, int aScreenCoordsY)
{
	// get the tile to interact with
	const auto currentPositionInGrid = m_transform->GetPositionInGrid();
	const auto orientationAsGridIncrement = m_orientation->GetOrientationAsGridIncrement();
	const auto gridPositionToInteract = currentPositionInGrid + orientationAsGridIncrement;

	const auto gameObjectOnTileToInteract = m_GOgridMap->CheckForGameObjectOnTile(gridPositionToInteract);

	m_inventory->ObjectBeingHeld()->GetInteractable()->InteractWith(gameObjectOnTileToInteract, *m_GOgridMap);
	/*if (gameObjectOnTileToInteract == nullptr)
	{
		printf("no GO on tile\n");
		//can activeItem interact with nullptr?
			// yes -> interact
			// else -> return
		
			// ask the inventory what the active item is 
		std::unique_ptr<GameObject> seed = std::make_unique<GameObject>(gridPositionToInteract);
		seed->AddComponent<SpriteRenderer>("assets\\player.png");
		seed->Start();

		OnTryToCreateGameObjectEvent->TriggerEvent(std::move(seed), gridPositionToInteract);
	}
	else
	{
		printf("GO on tile\n");
		// can aGOtoInteractWith interact with activeItem?
			// yes -> interact
			// else -> return
	}*/
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
	printf("destroyed interactWithWorld\n");
}