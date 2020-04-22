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

void Transform::UpdateMovement(short x, short y)
{
	m_transform.move(x, y);
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