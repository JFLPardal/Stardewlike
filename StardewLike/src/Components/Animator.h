#pragma once
#include "Component.h"
#include "Animation.h"

#include "Enums.h"
#include "Constants.h"

/*
	Animator is responsible for holding the current animation of a GameObject
	and pass the correct sprite sheet position to be rendered to SpriteRenderer, 
	based on the GameObject's state.
*/

class Orientation;

class SpriteSheetTile
{
	typedef Vector2i SpriteSheetIndex;
	typedef Vector2i TileSize;
public:
	SpriteSheetTile(SpriteSheetIndex aSpriteSheetIndex, TileSize aTileSize)
		: m_tile(aSpriteSheetIndex.GetVector(), aTileSize.GetVector())
	{}

	const sf::IntRect& GetRect()const { return m_tile; };
private:
	sf::IntRect m_tile;
};

class Animator : public Component
{
public:
	Animator() { printf("animator\n"); }
	~Animator();

	void Start() override;
	// bool CurrentAnimationHasMoreThanOneFrame() const {return m_currentAnimation.size() > 1; }
	const SpriteSheetTile& GetSpriteSheetTileToDraw() const;
private:
	void UpdateCurrentAnimation(State aNewState);

	Animation m_currentAnimation;
	Orientation* m_orientation{ nullptr };
	EventIndex m_StateChangedIndex = -2;
};