#include "pch.h"
#include "Component.h"

#include "GameObject.h"

Component::Component() noexcept
{
	printf("creating Component: ");
}

void Component::SetOwner(GameObject& aOwner) noexcept
{ 
	m_owner = &aOwner; 
}