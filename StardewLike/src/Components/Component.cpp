#include "pch.h"
#include "Component.h"

#include "GameObject.h"

IComponent::IComponent()
{
	printf("creating IComponent: ");
}

void IComponent::SetOwner(GameObject& aOwner)
{ 
	m_owner = &aOwner; 
}