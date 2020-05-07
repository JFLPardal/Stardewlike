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
	const sf::IntRect& GetRectToDraw() const { return m_currentRect; }
private:
	void UpdateRectToDraw(PossibleOrientation aCurrentOrientation);

	static std::map<PossibleOrientation, sf::Vector2i> orientationToSpriteIndex;

	sf::IntRect m_currentRect{ 0, 0, TILE_W, TILE_H};
	EventIndex m_OrientationChangedIndex = -2;
};