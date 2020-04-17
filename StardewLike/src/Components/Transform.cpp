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
	m_x = m_owner->GetComponent<Input>()->OnInputMoveAddObserver
									(std::function<void(short, short)>
										(std::bind(&Transform::UpdateMovement
													,this
													,std::placeholders::_1, std::placeholders::_2)));
}

void Transform::UpdateMovement(short x, short y)
{
	m_transform.move(x, y);
}

void Transform::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		m_owner->GetComponent<Input>()->OnInputMoveRemoveObserver(m_x);
	}
}
