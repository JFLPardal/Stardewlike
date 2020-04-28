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

	static sf::Vector2i GridPosition(float aScreenPosX, float aScreenPosY);
	static sf::Vector2i GridPosition(sf::Vector2f aScreenPos);
private:
	static constexpr int m_tileWidth	= 32;
	static constexpr int m_tileHeight	= 32;
	static constexpr int m_gridWidth	= 1024 / m_tileWidth;	// add these values to 'Constants.h"
	static constexpr int m_gridHeight	= 768 / m_tileHeight;	// add these values to 'Constants.h"
};