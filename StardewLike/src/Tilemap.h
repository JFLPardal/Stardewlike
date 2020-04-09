#pragma once
#include "SFML/Graphics.hpp"

class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	bool Load(const std::string& aTileset, sf::Vector2u aTileSize, const int* aTiles, unsigned int aWidth, unsigned int aHeight);
	virtual void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const;

private:
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
};