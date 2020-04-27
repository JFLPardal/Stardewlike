#include "pch.h"
#include "WindowEventHandler.h"

WindowEventHandler::WindowEventHandler()
	: m_onMouseMoveEvent(std::make_unique<MouseMovedEvent>())
	, m_onMouseLeftClickedEvent(std::make_unique<MouseLeftClikedEvent>())
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
		if (aEvent.mouseButton.button == sf::Mouse::Button::Left)
		{
			m_onMouseLeftClickedEvent->TriggerEvent(aEvent.mouseButton.x, aEvent.mouseButton.y);
		}
		//printf("mouse pressed: %d %d %d\n", aEvent.mouseButton.x, aEvent.mouseButton.y, aEvent.mouseButton.button);
	}
	if (aEvent.type == sf::Event::MouseMoved)
	{
		m_onMouseMoveEvent->TriggerEvent(aEvent.mouseMove.x, aEvent.mouseMove.y);
	}

	return m_isOpen;
}
