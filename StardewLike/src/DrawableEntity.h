#pragma once
#include "SFML/Graphics.hpp"

class DrawableEntity : public sf::Drawable, public sf::Transformable
{
public:
	DrawableEntity(const char* textureFilePath);
	virtual ~DrawableEntity() {};

	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	// TODO optimize, this should store a pointer to a texture and all textures should be stored in a single class
	sf::Texture m_Texture;
	sf::Sprite  m_Sprite;
};
