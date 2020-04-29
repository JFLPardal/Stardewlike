#include "pch.h"
#include "InteractWithWorld.h"

#include "WindowEventHandler.h"
#include "Transform.h"
#include "Orientation.h"
#include "GameObject.h"

InteractWithWorld::InteractWithWorld(WindowEventHandler* aWindowEventHandler)
	:m_windowEventHandler(aWindowEventHandler)
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

	printf("orientation: (%d , %d)\n", orientationAsGridIncrement.x, orientationAsGridIncrement.y);

	auto gridPositionToInteract = positionInGrid + orientationAsGridIncrement;
	printf("interact with: (%d , %d)\n", gridPositionToInteract.x, gridPositionToInteract.y);
	// mapData.Interact(gridPositionToInteract);
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
}