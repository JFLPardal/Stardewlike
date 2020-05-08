#pragma once
#include "Component.h"
#include "Enums.h"
#include "Constants.h"

/*
	Animator is responsible for calculating the apropriate sprite on the 
	sprite sheet that should be rendered, based on the GameObject's state.
*/

class Animator : public Component
{
public:
	Animator() { printf("animator\n"); }
	~Animator();

	void Start() override;
	// bool CurrentAnimationHasMoreThanOneFrame() const {return m_currentAnimation.size() > 1; }
	const sf::IntRect& GetRectToDraw() const { return m_currentRect; } // {return sf::Rect{m_currentAnimation.at(m_currentIndex).x, m_currentAnimation.at(m_currentIndex).y, 32, 32}; }
private:
	void UpdateRectToDraw(PossibleOrientation aCurrentOrientation);
	void UpdateCurrentAnimation(State aNewState);

	static std::map<PossibleOrientation, sf::Vector2i> orientationToSpriteIndex;
	std::vector<sf::Vector2i> m_currentAnimation;
	size_t m_currentIndex = 0;
	sf::IntRect m_currentRect{ 0, 0, TILE_W, TILE_H};
	EventIndex m_OrientationChangedIndex = -2;
	EventIndex m_StateChangedIndex = -2;
};