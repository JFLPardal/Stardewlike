#include "pch.h"
#include "Input.h"

#include "SFML/Window/Keyboard.hpp"
#include "IEvent.h"

Input::Input()
	:OnMovementKeyPressedEvent (std::make_unique<MovementKeyPressedEvent>())
{
	printf("input\n");
}

// xInput and yInput MUST be a value [0,1]
void Input::Update()
{
	// won't support joystick movement with short 
	short xInput = 0, yInput = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) yInput--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) xInput--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) yInput++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) xInput++;

	assert(xInput <= 1 && yInput <= 1);
	if (xInput != 0 || yInput != 0)
		OnMovementKeyPressedEvent->TriggerEvent<short, short>(xInput, yInput);
}

Input::~Input()
{
	printf("destroyed input\n");
}