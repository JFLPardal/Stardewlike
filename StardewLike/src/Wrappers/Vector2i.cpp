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
