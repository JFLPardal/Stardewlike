#include "pch.h"
#include "Tilemap.h"

/*std::vector<int> tileMap =
{
	0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
	1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
	0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
	0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
	0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
	2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
	0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
};*/

std::vector<int> tileMap =
{
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};

bool Tilemap::Load(const std::string& aTileset, sf::Vector2u aTileSize, unsigned int aWidth, unsigned int aHeight)
{
	// load tileset
	if (! m_Tileset.loadFromFile(aTileset))
		return false;

	// change vertex array's properties
	m_Vertices.setPrimitiveType(sf::Quads);
	m_Vertices.resize(aWidth * aHeight * 4);

	// populate the vertex array, with one quad per tile
	for (size_t i = 0; i < aWidth; ++i)
	{
		for (size_t j = 0; j < aHeight; ++j)
		{
			// get current tile number
			const int tileNumber = tileMap.at(i + j * aWidth);

			// find its position in the tileset texture
			const int tu = tileNumber % (m_Tileset.getSize().x / aTileSize.x);
			const int tv = tileNumber / (m_Tileset.getSize().x / aTileSize.x);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_Vertices[(i + j * aWidth) * 4];
			
			// define its 4 corner
			quad[0].position = sf::Vector2f(i * aTileSize.x, j * aTileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * aTileSize.x, j * aTileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * aTileSize.x, (j + 1)* aTileSize.y);
			quad[3].position = sf::Vector2f(i * aTileSize.x, (j + 1)* aTileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * aTileSize.x, tv * aTileSize.y);
			quad[1].texCoords = sf::Vector2f((tu + 1) * aTileSize.x, tv * aTileSize.y);
			quad[2].texCoords = sf::Vector2f((tu + 1) * aTileSize.x, (tv + 1) * aTileSize.y);
			quad[3].texCoords = sf::Vector2f(tu * aTileSize.x, (tv + 1)* aTileSize.y);
		}
	}
	return true;
}

void Tilemap::draw(sf::RenderTarget & aTarget, sf::RenderStates aStates) const
{
	// apply transform
	aStates.transform *= getTransform();

	//apply the tileset texture
	aStates.texture = &m_Tileset;

	// draw the vertex array
	aTarget.draw(m_Vertices, aStates);
}
