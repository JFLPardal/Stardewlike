#include "pch.h"
#include "Transform.h"

#include "GameObject.h"
#include "Input.h"

Transform::Transform(int aInitialX, int aInitialY)
{
	m_transform.setPosition(aInitialX, aInitialY);
	printf("transform\n");
}

void Transform::Start()
{
	m_moveKeyPressedIndex = m_owner->GetComponent<Input>()->OnMovementKeyPressedEvent->AddCallback(MOVEMENT_KEY_PRESSED(&Transform::UpdateMovement));
}

void Transform::UpdateMovement(short aX, short aY)
{
	// the first case is so that it is not necessary to use a square root to normalize the arguments, but this forces aX and aY to be between 0 and 1!
	if (aX != 0 && aY != 0)
		m_transform.move(aX * .707, aY * .707);
	else
		m_transform.move(aX, aY);
}

Transform::~Transform()
{
	auto InputComponent = m_owner->GetComponent<Input>();
	if (InputComponent) InputComponent->OnMovementKeyPressedEvent->RemoveCallback(m_moveKeyPressedIndex);
	printf("destroyed transform\n");
}