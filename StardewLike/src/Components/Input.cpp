#include "Input.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/Rect.hpp"

#include "../IEvent.h"

Input::Input()
{
	OnInputMoveEvent = std::make_unique<IEvent<void(short, short)>>();
	printf("input\n");
}

Input::~Input()
{
	printf("destroyed input component\n");
}

void Input::Update()
{
	// won't support joystick movement with short 
	short xInput = 0, yInput = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		printf("moving to the right\n");
		xInput++;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		printf("moving to the left\n");
		xInput--;
	}
	if (xInput != 0 || yInput != 0)
		OnInputMoveEvent->TriggerEvent<short, short>(xInput, yInput);
}