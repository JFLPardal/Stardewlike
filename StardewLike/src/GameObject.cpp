#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"
#include "GridRepresentation.h"
#include "IInteractable.h"

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
	for (auto& component : m_componentList)
	{
		auto componentAsInteractable = dynamic_cast<IInteractable*>(component.get());
		if (componentAsInteractable)
		{
			m_interactable = componentAsInteractable;
			printf("found it :3\n");
			return;
		}
	}
}

void GameObject::Update()
{
	for (auto& component : m_componentList)
	{
		component->Update();
	}
}

/// This functions assures that the components are destroyed in the reverse order they where created
void GameObject::RemoveAllComponents()
{
	std::for_each(m_componentList.rbegin(), m_componentList.rend(), [](std::unique_ptr<Component>& component) {component.reset(); });
}

GameObject::~GameObject()
{
	RemoveAllComponents();
	static int numbah = 0;
	printf("destroyed GO %d\n", numbah);
	numbah++;
}