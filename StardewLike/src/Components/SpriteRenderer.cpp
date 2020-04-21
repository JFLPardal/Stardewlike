#include "SpriteRenderer.h"
#include <cstdio>
#include "Transform.h"
#include "Input.h"	
#include "../GameObject.h"

SpriteRenderer::SpriteRenderer(const char* spriteFilePath)
{
	printf(" spriteRenderer with sprite %s\n", spriteFilePath);
	if (!m_Texture.loadFromFile(spriteFilePath))
	{
		printf("texture not loaded\n");
	}

	// create sprite based on texture
	m_Sprite.setTexture(m_Texture);
	m_Sprite.setOrigin(.5f * m_Texture.getSize().x, .5f * m_Texture.getSize().y);
	m_Sprite.setScale(.05f, .05f);

}

void SpriteRenderer::Start()
{
	m_transform = m_owner->GetComponent<Transform>();
	index = m_owner->GetComponent<Input>()->OnInputMoveEvent->AddCallback(MOVE_KEY_PRESSED(&SpriteRenderer::SetSpriteBasedOnDirection));
}

void SpriteRenderer::Update()
{
	m_Sprite.setPosition(m_transform->GetPosition());
}

void SpriteRenderer::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const
{
	aTarget.draw(m_Sprite, aStates);
}

void SpriteRenderer::SetSpriteBasedOnDirection(short aX, short aY)
{
	if (aX > 0)
	{
		m_Sprite.setColor(sf::Color::Cyan);
	}
	else
	{
		m_Sprite.setColor(sf::Color::Magenta);
	}
}

SpriteRenderer::~SpriteRenderer()
{
	auto InputComponent = m_owner->GetComponent<Input>();
	if (InputComponent) InputComponent->OnInputMoveEvent->RemoveCallback(index);

	printf("destroyed spriteRenderer component\n");
}