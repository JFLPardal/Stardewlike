#pragma once

/*
	GridRepresentation is responsible for knowing how to convert from pixel coordenates
	to a map representation(grid) index.

	// TODO
	As it is, there is only enough grid to represent what the window is rendering,
	anything outside of the rendered window is going to abort the program
*/

class GridRepresentation
{
public:
	GridRepresentation() = delete;

	static Vector2i ScreenToGridPosition(float aScreenPosX, float aScreenPosY);
	static Vector2i ScreenToGridPosition(sf::Vector2f aScreenPos);
	static sf::Vector2f GridToScreenPosition(Vector2i aGridPos);
};