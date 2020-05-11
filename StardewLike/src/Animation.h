#pragma once

class Vector2i;

class Animation
{
public:
	Animation(std::initializer_list<Vector2i> aSpriteSheetIndexes);
	Animation() = default;
	~Animation() = default;

	Vector2i CurrentSpriteSheetRect() const;
	void SetNewAnimation(const Animation& aNewAnimation);
private:
	std::vector<Vector2i> m_currentAnimation;
	size_t m_currentIndex = 0;
};