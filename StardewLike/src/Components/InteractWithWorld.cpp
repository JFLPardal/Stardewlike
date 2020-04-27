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
	// get player's position in grid
	auto positionInGrid = m_transform->GetPositionInGrid();
	// get player's orientation in increment
	auto orientationAsGridIncrement = m_orientation->GetOrientationAsGridIncrement();
	printf("(%d , %d)\n", orientationAsGridIncrement.x, orientationAsGridIncrement.y);
	//interact with that position
	auto gridPositionToInteract = positionInGrid + orientationAsGridIncrement;
	//  ...GridInteract(gridPositionToInteract);
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
}