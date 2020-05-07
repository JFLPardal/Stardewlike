#include "pch.h"
#include "SpriteRenderer.h"

#include "GameObject.h"
#include "Transform.h"
#include "Input.h"	
#include "Orientation.h"
#include "Animator.h"

SpriteRenderer::SpriteRenderer(const char* spriteFilePath, bool aKeepOriginalScale)
{
	assert(m_texture.loadFromFile(spriteFilePath) && "texture not loaded");
	printf("sprite renderer\n");
	// create sprite based on texture
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(.5f * TILE_W, .5f * TILE_H);
	if(!aKeepOriginalScale)
		m_sprite.setScale(.05f, .05f);
}

void SpriteRenderer::Start()
{
	m_transform = m_owner->GetComponent<Transform>();
	m_orientation = m_owner->GetComponent<Orientation>();
	m_animator = m_owner->GetComponent<Animator>();
}

void SpriteRenderer::Update()
{
	m_sprite.setPosition(m_transform->GetPosition());
	
	if(m_animator != nullptr)
	{
		m_sprite.setTextureRect(m_animator->GetRectToDraw());
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