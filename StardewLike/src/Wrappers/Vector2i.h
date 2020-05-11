#pragma once

/*
	Vector2i is a wrapper for the sf::Vector2i
*/

class Vector2i
{
public:
	Vector2i();
	Vector2i(int aX, int aY);
	Vector2i(sf::Vector2i aVector);

	int X() const { return m_vec.x; }
	int Y() const { return m_vec.y; }

	const sf::Vector2i& GetVector() const { return m_vec; }
private:
	sf::Vector2i m_vec;
};
