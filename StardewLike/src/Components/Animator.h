#pragma once
#include "Component.h"
#include "Enums.h"
#include "Constants.h"

/*
	Animator is responsible for calculating the apropriate sprite on the 
	sprite sheet that should be rendered, based on the GameObject's state.
*/

class Orientation;

class Animator : public Component
{
public:
	Animator() { printf("animator\n"); }
	~Animator();

	void Start() override;
	// bool CurrentAnimationHasMoreThanOneFrame() const {return m_currentAnimation.size() > 1; }
	const sf::IntRect& GetRectToDraw() const { return m_currentRect; } // {return sf::Rect{m_currentAnimation.at(m_currentIndex).x, m_currentAnimation.at(m_currentIndex).y, 32, 32}; }
private:
	void UpdateCurrentAnimation(State aNewState);

	std::vector<sf::Vector2i> m_currentAnimation;
	sf::IntRect m_currentRect{ 0, 0, TILE_W, TILE_H};
	size_t m_currentIndex = 0;

	Orientation* m_orientation{ nullptr };
	EventIndex m_StateChangedIndex = -2;
};