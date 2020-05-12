#pragma once

// TODO add description if this files stays on the project
class Tilemap : public sf::Drawable, public sf::Transformable
{
public:
	bool Load(const std::string& aTileset, sf::Vector2u aTileSize, unsigned int aWidth, unsigned int aHeight);
	void draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const override;

private:
	sf::VertexArray m_Vertices;
	sf::Texture m_Tileset;
};