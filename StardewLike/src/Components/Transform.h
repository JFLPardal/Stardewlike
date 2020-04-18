#pragma once
#include "Component.h"
#include "SFML/Graphics/Transformable.hpp"
#include <list>
#include <functional>

class Transform : public Component
{
public:
	Transform();
	~Transform();

	void Start() override;
	void Update() override;
	
	inline void UpdateMovement(short x, short y);
	
	inline sf::Vector2f GetPosition() { return m_transform.getPosition(); }
	inline int X() const { return m_x; }
private:
	size_t m_x = 43;
	sf::Transformable m_transform;
};