#include "pch.h"
#include "SpriteRenderer.h"

#include "GameObject.h"
#include "Transform.h"
#include "Input.h"	
#include "Orientation.h"

SpriteRenderer::SpriteRenderer(const char* spriteFilePath, bool aKeepOriginalScale)
{
	assert(m_texture.loadFromFile(spriteFilePath) && "texture not loaded");
	printf("sprite renderer\n");
	// create sprite based on texture
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(.5f * m_texture.getSize().x, .5f * m_texture.getSize().y);
	if(!aKeepOriginalScale)
		m_sprite.setScale(.05f, .05f);
}

void SpriteRenderer::Start()
{
	m_transform = m_owner->GetComponent<Transform>();
	m_orientation = m_owner->GetComponent<Orientation>();
}

void SpriteRenderer::Update()
{
	m_sprite.setPosition(m_transform->GetPosition());
	
	// update sprite based on mouse position relative to this sprite
	if(m_orientation)
	{
		const auto currentOrientation = m_orientation->GetOrientation();
		switch (currentOrientation)
		{
		case up:
			m_sprite.setColor(sf::Color::Cyan);
			break;
		case right:
			m_sprite.setColor(sf::Color::Magenta);
			break;
		case down:
			m_sprite.setColor(sf::Color::Yellow);
			break;
		case left:
			m_sprite.setColor(sf::Color::White);
			break;
		}
	}
}

void SpriteRenderer::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const
{
	aTarget.draw(m_sprite, aStates);
}

SpriteRenderer::~SpriteRenderer()
{
	printf("destroyed spriteRenderer\n");
}