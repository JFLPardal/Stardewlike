#include "pch.h"
#include "SpriteRenderer.h"

#include "GameObject.h"
#include "Transform.h"
#include "Input.h"	
#include "Orientation.h"

SpriteRenderer::SpriteRenderer(const char* spriteFilePath)
{
	printf(" spriteRenderer with sprite %s\n", spriteFilePath);
	if (!m_texture.loadFromFile(spriteFilePath))
	{
		printf("texture not loaded\n");
	}

	// create sprite based on texture
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(.5f * m_texture.getSize().x, .5f * m_texture.getSize().y);
	m_sprite.setScale(.05f, .05f);

}

void SpriteRenderer::Start()
{
	m_transform = m_owner->GetComponent<Transform>();
	m_eMoveKeyPressedIndex = m_owner->GetComponent<Input>()->OnInputMoveEvent->AddCallback(MOVE_KEY_PRESSED(&SpriteRenderer::SetSpriteBasedOnDirection));
	m_orientation = m_owner->GetComponent<Orientation>();
}

void SpriteRenderer::Update()
{
	m_sprite.setPosition(m_transform->GetPosition());
	
	// update sprite based on mouse position relative to this sprite
	auto currentOrientation = m_orientation->GetOrientation();
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

void SpriteRenderer::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const
{
	aTarget.draw(m_sprite, aStates);
}

void SpriteRenderer::SetSpriteBasedOnDirection(short aX, short aY)
{
	/*if (aX > 0)
	{
		m_sprite.setColor(sf::Color::Cyan);
	}
	else
	{
		m_sprite.setColor(sf::Color::Magenta);
	}*/
}

SpriteRenderer::~SpriteRenderer()
{
	auto InputComponent = m_owner->GetComponent<Input>();
	if (InputComponent) InputComponent->OnInputMoveEvent->RemoveCallback(m_eMoveKeyPressedIndex);

	printf("destroyed spriteRenderer component\n");
}