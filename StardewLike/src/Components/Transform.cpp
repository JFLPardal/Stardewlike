#include "Transform.h"
#include <iostream>

Transform::Transform()
{
	m_transform.setPosition(500, 500);
	printf("transform\n");
}

void Transform::Update()
{
	m_transform.move(1, 0);
}
