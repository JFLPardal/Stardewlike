#include "pch.h"
#include "Component.h"

#include "GameObject.h"

Component::Component()
{
	printf("creating Component: ");
}

void Component::SetOwner(GameObject& aOwner)
{ 
	m_owner = &aOwner; 
}