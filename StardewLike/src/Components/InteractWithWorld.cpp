#include "pch.h"
#include "InteractWithWorld.h"

#include "WindowEventHandler.h"

InteractWithWorld::InteractWithWorld(WindowEventHandler* aWindowEventHandler)
	:m_windowEventHandler(aWindowEventHandler)
{
}

void InteractWithWorld::Start()
{
	m_mouseLeftClickedIndex = m_windowEventHandler->m_onMouseLeftClickedEvent->AddCallback(MOUSE_LEFT_CLICKED(&InteractWithWorld::Interact));
}

void InteractWithWorld::Interact(int aScreenCoordsX, int aScreenCoordsY)
{
	printf("interacting with pos: (%d, %d)\n", aScreenCoordsX, aScreenCoordsY);
}

InteractWithWorld::~InteractWithWorld()
{
	m_windowEventHandler->m_onMouseLeftClickedEvent->RemoveCallback(m_mouseLeftClickedIndex);
}