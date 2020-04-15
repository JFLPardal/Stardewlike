#include "Input.h"
#include "SFML/Window/Keyboard.hpp"
#include "SFML/Graphics/Rect.hpp"

void Input::Update()
{
	short xInput = 0, yInput = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		printf("moving to the right\n");
		xInput++;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		printf("moving to the left\n");
		xInput--;
	}
	OnInputMove(xInput, yInput);
}

void Input::OnInputMove(short x, short y)
{
	for (auto& observer : e_onInputMove)
	{
		observer(x, y);
	}
}