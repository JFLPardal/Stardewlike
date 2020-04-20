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

size_t Input::OnMoveKeyPressedRegister(std::function<void(short, short)> functionToCall)
{
	if (functionToCall != nullptr)
	{
		return OnInputMoveEvent->AddFunctionToListeners(functionToCall);
	}
	return -1; // TODO change for exception?
}

void Input::OnMoveKeyPressedUnregister(size_t aIndex)
{
	OnInputMoveEvent->RemoveFunctionFromListeners(aIndex);
}