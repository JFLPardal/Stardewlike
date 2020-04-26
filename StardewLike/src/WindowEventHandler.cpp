#include "pch.h"
#include "WindowEventHandler.h"

WindowEventHandler::WindowEventHandler()
	:m_onMouseMoveEvent(std::make_unique<MouseMovedEvent>())
{
}

bool WindowEventHandler::ProcessEvent(const sf::Event& aEvent)
{
	bool m_isOpen = true;

	if (aEvent.type == sf::Event::Closed)
	{
		return !m_isOpen;
	}
	if (aEvent.type == sf::Event::KeyPressed)
	{
		//printf("key pressed: %d\n", aEvent.key.code);
	}
	if (aEvent.type == sf::Event::MouseButtonPressed)
	{
		//printf("mouse pressed: %d %d %d\n", aEvent.mouseButton.x, aEvent.mouseButton.y, aEvent.mouseButton.button);
	}
	if (aEvent.type == sf::Event::MouseMoved)
	{
		m_onMouseMoveEvent->TriggerEvent(aEvent.mouseMove.x, aEvent.mouseMove.y);
	}

	return m_isOpen;
}
