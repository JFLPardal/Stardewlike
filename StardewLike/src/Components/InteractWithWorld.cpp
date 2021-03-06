#include "pch.h"
#include "InteractWithWorld.h"

#include "WindowEventHandler.h"
#include "Transform.h"
#include "Orientation.h"
#include "GameObject.h"
#include "MapRepresentation/GameObjectGridMap.h"
#include "Inventory.h"
#include "IInteractable.h"
#include "InteractableTypes/Seed.h"
#include "InteractableTypes/NoInteractable.h"

InteractWithWorld::InteractWithWorld(WindowEventHandler* aWindowEventHandler, GameObjectGridMap& aGameObjectgridMap)
	: m_windowEventHandler(aWindowEventHandler)
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
	const auto currentPositionInGrid = m_transform->GetPositionInGrid();
	const auto orientationAsGridIncrement = m_orientation->GetOrientationAsGridIncrement();
	const auto gridPositionToInteract = currentPositionInGrid + orientationAsGridIncrement;
	GameObject* gameObjectOnTileToInteract = m_GOgridMap->CheckForGameObjectOnTile(gridPositionToInteract);

	// this is needed for those Interactable that can interact with an empty tile,
	// they need the grid position the player is interacting with
	if (gameObjectOnTileToInteract == nullptr)
	{
		GameObject nullGOJustGridPosition(gridPositionToInteract);
		nullGOJustGridPosition.AddComponent<NoInteractable>(gridPositionToInteract);
		//nullGOJustGridPosition.Start();
		gameObjectOnTileToInteract = &nullGOJustGridPosition;

		// TODO demeter violation
		//m_inventory->ObjectBeingHeld()->GetInteractable()->InteractWith(gameObjectOnTileToInteract, *m_GOgridMap);
		gameObjectOnTileToInteract->GetComponent<NoInteractable>()->InteractWith(m_inventory->ObjectBeingHeld(), *m_GOgridMap);
	}
	else if (gameObjectOnTileToInteract->GetInteractable() != nullptr)
	{
		gameObjectOnTileToInteract->GetInteractable()->InteractWith(m_inventory->ObjectBeingHeld(), *m_GOgridMap);
	}
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
	printf("destroyed interactWithWorld\n");
}