#include "pch.h"
#include "SpriteRenderer.h"

#include "GameObject.h"
#include "Transform.h"
#include "Input.h"	
#include "Orientation.h"

/// the vector is the grid position of each sprite on the tileSheet and the direction is the sprite of the player,
/// p.e. up has the coordenates, on the spritesheet, of the sprite of the player looking up
std::map<PossibleOrientation, sf::Vector2i> SpriteRenderer::orientationToSpriteIndex =
{
	{up,	sf::Vector2i(1 * TILE_W, 3 * TILE_H)},
	{right, sf::Vector2i(1 * TILE_W, 2 * TILE_H)},
	{down,	sf::Vector2i(1 * TILE_W, 0 * TILE_H)},
	{left,	sf::Vector2i(1 * TILE_W, 1 * TILE_H)}
};

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
}

void SpriteRenderer::Update()
{
	m_sprite.setPosition(m_transform->GetPosition());
	
	// update sprite based on mouse position relative to this sprite
	if(m_orientation)
	{
		OrientationChanged(m_orientation->GetOrientation());
	}
}

void SpriteRenderer::draw(sf::RenderTarget& aTarget, sf::RenderStates aStates) const
{
	aTarget.draw(m_sprite, aStates);
}

void SpriteRenderer::OrientationChanged(PossibleOrientation aNewOrientation)
{
	const sf::IntRect newRect(orientationToSpriteIndex.at(aNewOrientation), sf::Vector2i(TILE_W, TILE_H));
	m_sprite.setTextureRect(newRect);
}

SpriteRenderer::~SpriteRenderer()
{
	printf("destroyed spriteRenderer\n");
}