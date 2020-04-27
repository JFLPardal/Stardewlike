#include "pch.h"
#include "Orientation.h"

#include "WindowEventHandler.h"
#include "GameObject.h"
#include "Transform.h"

std::map<PossibleOrientation, sf::Vector2i> directionToGridIncrement
{
	{up		, sf::Vector2i(0, -1) },
	{right	, sf::Vector2i(+1, 0) },
	{down	, sf::Vector2i(0, +1) },
	{left	, sf::Vector2i(-1, 0) }
};

Orientation::Orientation(WindowEventHandler* aWindowEventHandler)
{
	assert(aWindowEventHandler != nullptr && "WindowEventHandler passed to Orientation Component is null");
	m_windowEventHandler = aWindowEventHandler;
}

void Orientation::Start()
{
	m_mouseMovedIndex = m_windowEventHandler->m_onMouseMoveEvent->AddCallback(MOUSE_MOVED(&Orientation::UpdateOrientation));
	m_transform = m_owner->GetComponent<Transform>();
}

sf::Vector2i Orientation::GetOrientationAsGridIncrement() const
{
	return directionToGridIncrement[m_currentOrientation]; 
}


void Orientation::UpdateOrientation(int aX, int aY)
{
	int objectX = m_transform->GetPosition().x;
	int objectY = m_transform->GetPosition().y;

	int deltaX = aX - objectX;
	int deltaY = aY - objectY;

	if (abs(deltaX) >= abs(deltaY))
		m_currentOrientation = (deltaX > 0) ? right : left;
	else
		m_currentOrientation = (deltaY > 0) ? down : up; // y increases from the top of the screen to the bottom
}

Orientation::~Orientation()
{
	m_windowEventHandler->m_onMouseMoveEvent->RemoveCallback(m_mouseMovedIndex); 
	printf("destroyed orientation\n");
}
