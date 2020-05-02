#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"
#include "GridRepresentation.h"

GameObject::GameObject(int aInitialX, int aInitialY) noexcept
{
	AddComponent<Transform>(aInitialX, aInitialY);
}

GameObject::GameObject(sf::Vector2i aGridPosition) noexcept
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
	static int numbah = 0;
	printf("destroyed GO %d\n", numbah);
	numbah++;
}