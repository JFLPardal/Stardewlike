#include "pch.h"
#include "Animation.h"

Animation::Animation(std::initializer_list<Vector2i> aSpriteSheetIndexes)
	:m_currentAnimation(aSpriteSheetIndexes)
{
}

Vector2i Animation::CurrentSpriteSheetRect() const
{
	return Vector2i(m_currentAnimation.at(m_currentIndex));
}

void Animation::SetNewAnimation(const Animation& aNewAnimation)
{
	m_currentAnimation = aNewAnimation.m_currentAnimation;
	m_currentIndex = 0;
}
