#pragma once
#include "Component.h"

/*
	Transform is responsible for updating the position, scale and rotation of the GO it is attached to.
*/

class Transform : public Component
{
public:
	Transform();
	~Transform();

	void Start() override;
	void Update() override;
	
	inline void UpdateMovement(short x, short y);
	
	inline sf::Vector2f GetPosition() { return m_transform.getPosition(); }
private:
	EventIndex m_eMoveKeyPressedIndex;
	sf::Transformable m_transform;
};