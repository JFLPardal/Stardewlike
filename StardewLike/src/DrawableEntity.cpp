#include "pch.h"
#include "DrawableEntity.h"

//#include "SFML/Graphics.hpp"

DrawableEntity::DrawableEntity(const char * aTextureFilePath)
{	
	setPosition(500, 500);
	// create texture
	if (!m_Texture.loadFromFile(aTextureFilePath))
	{
		printf("texture not loaded\n");
	}
	// create sprite based on texture
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(.5f * m_Texture.getSize().x, .5f * m_Texture.getSize().y);
	m_Sprite.setScale(.05f, .05f);
}

void DrawableEntity::update()
{
	short xInput = 0;
	// read input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//check collisions
		sf::Rect<float> invisibleWall = sf::Rect<float>(600, 300, 20, 300);
		auto boundingBox= m_Sprite.getGlobalBounds();
		if (!boundingBox.intersects(invisibleWall))
		{
			xInput = 1;
			move(.5f, 0.f);
		}
	}
	else
	{
		xInput = 0;
	}
	// update sprite based on orientation
	if (xInput > 0)
	{
		m_Sprite.setColor(sf::Color::Cyan);
	}
	else
	{
		m_Sprite.setColor(sf::Color::Magenta);
	}

	// update sprite's position
	m_Sprite.setPosition(getPosition());


}

void DrawableEntity::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const
{
	aTarget.draw(m_Sprite, aStates);
}
