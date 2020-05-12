#include "pch.h"
#include "WindowEventHandler.h"

WindowEventHandler::WindowEventHandler() noexcept
	: m_onMouseMoveEvent(std::make_unique<MouseMovedEvent>())
	, m_onMouseLeftClickedEvent(std::make_unique<MouseLeftClikedEvent>())
	, m_onNumberKeyPressedEvent(std::make_unique<KeyPressedEvent>())
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
		// if a number between 1 - 9 was pressed
		if(aEvent.key.code > 26 && aEvent.key.code < 36)
			m_onNumberKeyPressedEvent->TriggerEvent(aEvent.key.code - 26);
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
