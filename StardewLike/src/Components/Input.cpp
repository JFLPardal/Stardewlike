#include "Input.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/Rect.hpp"

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
	if(xInput != 0 || yInput != 0)
		OnInputMove(xInput, yInput);
}

void Input::OnInputMove(short x, short y)
{
	for (auto& observer : m_OnMoveKeyPressedCallbacks)
	{
		if(observer != nullptr) observer(x, y);
	}
}
