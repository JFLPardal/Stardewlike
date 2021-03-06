#pragma once
#include "Component.h"

/*
	Transform is responsible for updating the position, scale and rotation of the GO it is attached to.
*/

class Transform : public Component
{
public:
	Transform(int aInitialX, int aInitialY);
	~Transform();

	void Start() override;
	
	inline sf::Vector2f GetPosition() const { return m_transform.getPosition(); }
	Vector2i GetPositionInGrid() const;
private:
	inline void UpdateMovement(short x, short y);

	EventIndex m_moveKeyPressedIndex = -2;
	sf::Transformable m_transform;
};