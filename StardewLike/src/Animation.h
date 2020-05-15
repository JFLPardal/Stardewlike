#pragma once

/*
	Animation is an abstraction that defines the ways
	an animation can be interacted with.
	It is a collection of the points on a texture that defines each 
	index a sprite starts at on that texture, regardless of the size of the texture
*/

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