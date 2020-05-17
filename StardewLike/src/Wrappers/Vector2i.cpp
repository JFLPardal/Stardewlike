#include "pch.h"
#include "Vector2i.h"

Vector2i::Vector2i()
	:m_vec(-3,-3)
{
}

Vector2i::Vector2i(int aX, int aY)
	: m_vec(aX, aY)
{
}

Vector2i::Vector2i(sf::Vector2i aVector)
	: m_vec(aVector)
{
}

Vector2i operator+(const Vector2i& aVec1, const Vector2i& aVec2)
{
	return Vector2i(aVec1.X() + aVec2.X() ,
					aVec1.Y() + aVec2.Y() );
}
