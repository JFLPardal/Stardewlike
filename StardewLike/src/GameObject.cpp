#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"
#include "GridRepresentation.h"

GameObject::GameObject(int aInitialX, int aInitialY)
{
	AddComponent<Transform>(aInitialX, aInitialY);
}

GameObject::GameObject(sf::Vector2i aGridPosition)
{
	auto positionInScreenSpace = GridRepresentation::GridToScreenPosition(aGridPosition);
	AddComponent<Transform>(positionInScreenSpace.x, positionInScreenSpace.y);
}

void GameObject::Start()
{
	for (auto& component : m_componentList)
	{
		component->Start();
	}
	m_renderer = GetComponent<SpriteRenderer>();
}

void GameObject::Update()
{
	for (auto& component : m_componentList)
	{
		component->Update();
	}
}

GameObject::~GameObject()
{
	printf("destroyed GO\n");
}