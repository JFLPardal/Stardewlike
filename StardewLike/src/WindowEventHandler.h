#pragma once
#include "IEvent.h"

/*
	WindowEventHandler is responsible for capturing and broadcasting the events from the SFML window 
	like mouse movement, mouse click, keyboard key pressed, window resize and so forth
*/
#define MOUSE_MOVED(callbackFunction) std::function<void(int, int)>(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))
#define MOUSE_LEFT_CLICKED(callbackFunction) std::function<void(int, int)>(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

typedef IEvent<void(int, int)> MouseMovedEvent;
typedef IEvent<void(int, int)> MouseLeftClikedEvent;

class WindowEventHandler
{
public:
	WindowEventHandler() noexcept;
	~WindowEventHandler() = default;

	// return false if the Quit Window event was processed, true otherwise
	bool ProcessEvent(const sf::Event& aEvent);

	std::unique_ptr<MouseMovedEvent> m_onMouseMoveEvent;
	std::unique_ptr<MouseLeftClikedEvent> m_onMouseLeftClickedEvent;
};