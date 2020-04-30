#include "pch.h"
#include "InteractWithWorld.h"

#include "WindowEventHandler.h"
#include "Transform.h"
#include "Orientation.h"
#include "GameObject.h"
#include "GameObjectGridMap.h"

InteractWithWorld::InteractWithWorld(WindowEventHandler* aWindowEventHandler, GameObjectGridMap& aTileData)
	: OnTryToCreateGameObjectEvent(std::make_unique<TryToCreateGameObjectEvent>())
	, m_windowEventHandler(aWindowEventHandler)
	, m_tileData(&aTileData)
{
}

void InteractWithWorld::Start()
{
	m_mouseLeftClickedIndex = m_windowEventHandler->m_onMouseLeftClickedEvent->AddCallback(MOUSE_LEFT_CLICKED(&InteractWithWorld::Interact));
	m_transform = m_owner->GetComponent<Transform>();
	m_orientation = m_owner->GetComponent<Orientation>();
}

void InteractWithWorld::Interact(int aScreenCoordsX, int aScreenCoordsY)
{
	auto positionInGrid = m_transform->GetPositionInGrid();
	auto orientationAsGridIncrement = m_orientation->GetOrientationAsGridIncrement();

	//printf("orientation: (%d , %d)\n", orientationAsGridIncrement.x, orientationAsGridIncrement.y);

	auto gridPositionToInteract = positionInGrid + orientationAsGridIncrement;
	printf("interact with: (%d , %d)\n", gridPositionToInteract.x, gridPositionToInteract.y);

	//-------------------------------------------------------------------------------------------------------------
	auto gameObjectOnTile = m_tileData->CheckForGameObjectOnTile(gridPositionToInteract);
	if (gameObjectOnTile == nullptr)
	{
		printf("no GO on tile\n");
		GameObject* seedForExample = new GameObject(gridPositionToInteract);
		seedForExample->AddComponent<SpriteRenderer>("assets\\player.png");
		seedForExample->Start();
		
		OnTryToCreateGameObjectEvent->TriggerEvent(std::move(seedForExample), gridPositionToInteract);
		// TODO check if active item can interact with empty tile, if it can interact, else nothing happens
		//m_tileData->AddToGrid(new GameObject(), gridPositionToInteract);
		// TODO this  GO  instance has to be added to the vector of GO in GameApp as well
	}
	else
	{
		printf("GO on tile\n");
	}
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
}