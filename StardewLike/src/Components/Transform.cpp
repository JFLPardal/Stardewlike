#include "pch.h"
#include "Transform.h"

#include "GameObject.h"
#include "Input.h"

Transform::Transform()
{
	m_transform.setPosition(500, 500);
	printf("transform\n");
}

void Transform::Start()
{
	m_eMoveKeyPressedIndex = m_owner->GetComponent<Input>()->OnInputMoveEvent->AddCallback(MOVE_KEY_PRESSED(&Transform::UpdateMovement));
}

void Transform::UpdateMovement(short aX, short aY)
{
	// the first case is so that it is not necessary to use a square root to normalize the arguments, but this forces aX and aY to be between 0 and 1!
	if (aX != 0 && aY != 0)
		m_transform.move(aX * .707, aY * .707);
	else
		m_transform.move(aX, aY);
}

void Transform::Update()
{
}

Transform::~Transform()
{
	auto InputComponent = m_owner->GetComponent<Input>();
	if (InputComponent) InputComponent->OnInputMoveEvent->RemoveCallback(m_eMoveKeyPressedIndex);
	printf("destroyed transform\n");
}