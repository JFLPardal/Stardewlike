#pragma once
#include "Component.h"
#include "IEvent.h"

/*
	Input is responsible for getting the events that are keyboard and mouse related, and communicating them via 'IEvent'.

	EVENT_SOURCE:
	* OnMovementKeyPressedEvent: Event that is triggered when the keys on the keyboard responsible for moving the player are pressed
*/

typedef IEvent<void(short, short)> MovementKeyPressedEvent;

#define MOVEMENT_KEY_PRESSED(callbackFunction) std::function<void(short, short)>(std::bind(callbackFunction, this, std::placeholders::_1, std::placeholders::_2))

class Input : public Component
{
public:
	Input() noexcept;
	~Input();

	std::unique_ptr<MovementKeyPressedEvent> OnMovementKeyPressedEvent;

	void Update() override;
};
