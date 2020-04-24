#include "pch.h"
#include "Orientation.h"
#include "WindowEventHandler.h"

Orientation::Orientation(WindowEventHandler* aWindowEventHandler)
{
	assert(aWindowEventHandler != nullptr && "WindowEventHandler passed to Orientation Component is null");
	m_windowEventHandler = aWindowEventHandler;
}


void Orientation::Start()
{
	m_eMouseMovementIndex = m_windowEventHandler->m_onMouseMoveEvent->AddCallback(MOUSE_MOVED(&Orientation::UpdateOrientation));
}

void Orientation::Update()
{
}

PossibleOrientation Orientation::GetOrientation() const
{
	return m_currentOrientation;
}

void Orientation::UpdateOrientation(int aX, int aY)
{
	printf("updating orientation! %d %d\n", aX, aY);
}

Orientation::~Orientation()
{
	m_windowEventHandler->m_onMouseMoveEvent->RemoveCallback(m_eMouseMovementIndex);
}
