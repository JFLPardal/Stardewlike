#include "pch.h"
#include "GameObject.h"

#include "Components/SpriteRenderer.h"
#include "Components/Transform.h"
#include "MapRepresentation/GridRepresentation.h"
#include "IInteractable.h"

unsigned int GameObject::m_nextID = 0;

GameObject::GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, int aInitialX, int aInitialY) noexcept
	: m_stateMachine(std::move(aStateMachine))
	, m_data(std::move(aGOdata))
	, m_ID(m_nextID)
{
	m_nextID++;
	AddComponent<Transform>(aInitialX, aInitialY);
}

GameObject::GameObject(Vector2i aGridPosition) noexcept
	: m_ID(m_nextID)
{
	m_nextID++;
	auto positionInScreenSpace = GridRepresentation::GridToScreenPosition(aGridPosition);
	AddComponent<Transform>(positionInScreenSpace.x, positionInScreenSpace.y);
}

GameObject::GameObject(std::unique_ptr<GameObjectData> aGOdata, std::unique_ptr<StateMachine> aStateMachine, Vector2i aGridPosition) noexcept
	: GameObject(aGridPosition)
{
	m_stateMachine = std::move(aStateMachine);
	m_data = std::move(aGOdata);
	/*m_nextID++;
	auto positionInScreenSpace = GridRepresentation::GridToScreenPosition(aGridPosition);
	AddComponent<Transform>(positionInScreenSpace.x, positionInScreenSpace.y); */
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
	if(m_stateMachine)
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