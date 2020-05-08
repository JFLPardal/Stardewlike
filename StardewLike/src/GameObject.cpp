#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"
#include "GridRepresentation.h"
#include "IInteractable.h"

GameObject::GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, int aInitialX, int aInitialY) noexcept
	: m_stateMachine(std::move(aStateMachine))
	, m_data(std::move(aGOdata))
{
	AddComponent<Transform>(aInitialX, aInitialY);
}

GameObject::GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, sf::Vector2i aGridPosition) noexcept
	: m_stateMachine(std::move(aStateMachine))
	, m_data(std::move(aGOdata))
{
	auto positionInScreenSpace = GridRepresentation::GridToScreenPosition(aGridPosition);
	AddComponent<Transform>(positionInScreenSpace.x, positionInScreenSpace.y);
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
			break;
		}
	}
	m_stateMachine->Start(this);
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