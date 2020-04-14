#pragma once
#include "Component.h"
#include "SFML/Graphics/Transformable.hpp"

class Transform : public Component
{
public:
	Transform();
	~Transform() { printf(" transform\n"); }
	void Update() override;

	inline sf::Vector2f GetPosition() { return m_transform.getPosition(); }
	int X() const { return m_x; }

private:
	int m_x = 43;
	sf::Transformable m_transform;
};