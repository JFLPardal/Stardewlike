#include "pch.h"
#include "Orientation.h"

void Orientation::Update()
{
	auto mousePositon = sf::Mouse::getPosition();
	printf("mouse position: %d %d \n", mousePositon.x, mousePositon.y);
}

PossibleOrientation Orientation::GetOrientation() const
{
	return m_currentOrientation;
}
