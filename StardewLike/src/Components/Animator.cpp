#include "pch.h"
#include "Animator.h"

#include "Constants.h"
#include "GameObject.h"
#include "Orientation.h"

/// the vector is the grid position of each sprite on the tileSheet and the direction is the sprite of the player,
/// p.e. up has the coordenates, on the spritesheet, of the sprite of the player looking up
std::map<PossibleOrientation, sf::Vector2i> Animator::orientationToSpriteIndex =
{
	{up,	sf::Vector2i(1 * TILE_W, 3 * TILE_H)},
	{right, sf::Vector2i(1 * TILE_W, 2 * TILE_H)},
	{down,	sf::Vector2i(1 * TILE_W, 0 * TILE_H)},
	{left,	sf::Vector2i(1 * TILE_W, 1 * TILE_H)}
};


void Animator::Start()
{
	m_OrientationChangedIndex = m_owner->GetComponent<Orientation>()->OnOrientationChangedEvent->AddCallback(ORIENTATION_CHANGED(&Animator::UpdateRectToDraw));
}

void Animator::UpdateRectToDraw(PossibleOrientation aCurrentOrientation)
{
	 m_currentRect = sf::IntRect(orientationToSpriteIndex.at(aCurrentOrientation), sf::Vector2i(TILE_W, TILE_H));
}

Animator::~Animator()
{
	m_owner->GetComponent<Orientation>()->OnOrientationChangedEvent->RemoveCallback(m_OrientationChangedIndex);
	printf("destroyed transform\n");
}
