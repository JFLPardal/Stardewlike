#include "pch.h"
#include "Transform.h"

#include "GameObject.h"
#include "Input.h"
#include "GridRepresentation.h"
#include "Constants.h"

Transform::Transform(int aInitialX, int aInitialY)
{
	m_transform.setPosition(static_cast<float>(aInitialX), static_cast<float>(aInitialY));
	printf("transform\n");
}

/*
<template ComponentType>
	class EventInfo
	{
		EventInfo<ComponentType>(GameObject& owner, &function functionToCall)
		{
			m_caller = owner->GetComponent<ComponentType>();
			m_index = m_caller->Event->AddCallback(MOVEMENT_KEY_PRESSED(&Transform::UpdateMovement));
		}

		~EventInfo()
		{
			m_caller->OnMovementKeyPressedEvent->RemoveCallback(m_index);
		}
		T 
		Component& m_caller;
		size_t m_index;
	}
*/

void Transform::Start()
{
	if(m_owner->GetComponent<Input>())
		m_moveKeyPressedIndex = m_owner->GetComponent<Input>()->OnMovementKeyPressedEvent->AddCallback(MOVEMENT_KEY_PRESSED(&Transform::UpdateMovement));
}

sf::Vector2i Transform::GetPositionInGrid() const
{
	auto gridPosition = GridRepresentation::ScreenToGridPosition(m_transform.getPosition());
	//printf("grid position is: [%d , %d]\n", gridPosition.x, gridPosition.y);
	return gridPosition;
}

void Transform::UpdateMovement(short aX, short aY)
{
	// the first case is so that it is not necessary to use a square root to normalize the arguments, but this forces aX and aY to be between 0 and 1!
	if (aX != 0 && aY != 0)
		m_transform.move(aX * NORMALIZED_UNIT_VECTOR_LENGTH,
						 aY * NORMALIZED_UNIT_VECTOR_LENGTH);
	else
		m_transform.move(aX, aY);
}

Transform::~Transform()
{
	auto InputComponent = m_owner->GetComponent<Input>();
	if (InputComponent) InputComponent->OnMovementKeyPressedEvent->RemoveCallback(m_moveKeyPressedIndex);
	printf("destroyed transform\n");
}