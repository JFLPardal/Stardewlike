#include "Transform.h"
#include <iostream>
#include "../GameObject.h"
#include "Input.h"

Transform::Transform()
{
	m_transform.setPosition(500, 500);
	printf("transform\n");
}

void Transform::Start()
{
	//m_owner->GetComponent<Input>()->OnInputMoveAddObserver(&this->UpdateMovement);
	m_owner->GetComponent<Input>()->OnInputMoveAddObserver([&f = m_transform](short a, short b) {f.setPosition(f.getPosition().x + a, f.getPosition().y + b); });
	//m_owner->GetComponent<Input>()->e_onInputMove.emplace_back(this->UpdateMovement);

}

void Transform::UpdateMovement(short x, short y)
{
	printf("calling update movemente :O\n");
}

void Transform::Update()
{
}
